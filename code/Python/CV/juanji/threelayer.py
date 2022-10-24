import tensorflow as tf
from tensorflow.examples.tutorials.mnist import input_data
mnist = input_data.read_data_sets("MNIST_data", one_hot = True)

x = tf.placeholder(tf.float32, shape = [None, 784])
y_ = tf.placeholder(tf.float32, shape = [None, 10])

hide_layer_size = 500
batch_size = 100
base_learn_rate = 0.8
learn_decay_rate = 0.99
movingaverage_decay = 0.99
regularization_rate = 0.0001

def reference(input_data, avg_class, weight1, bias1, weight2, bias2):
    if (avg_class == None):
        layer1 = tf.nn.relu(tf.matmul(input_data, weight1) + bias1)
        return tf.matmul(layer1, weight2) + bias2
    else:
        layer1 = tf.nn.relu(tf.matmul(input_data, avg_class.average(weight1)) + avg_class.average(bias1))
        return tf.matmul(layer1, avg_class.average(weight2)) + avg_class.average(bias2)


weight_1 = tf.Variable(tf.truncated_normal([784, 500], stddev = 0.1))
bias_1 = tf.Variable(tf.constant(0.1, tf.float32))

weight_2 = tf.Variable(tf.truncated_normal([500, 10], stddev = 0.1))
bias_2 = tf.Variable(tf.constant(0.1, tf.float32))

y = reference(x, None, weight_1, bias_1, weight_2, bias_2)

global_step = tf.Variable(0, False)
average_class = tf.train.ExponentialMovingAverage(movingaverage_decay, global_step)
average_op = average_class.apply(tf.trainable_variables())

average_y = reference(x, average_class, weight_1, bias_1, weight_2, bias_2)

cross_entropy_y = tf.nn.sparse_softmax_cross_entropy_with_logits \
    (labels = tf.arg_max(y_, 1), logits = y)
cross_entropy_y_mean = tf.reduce_mean(cross_entropy_y)

regularization = tf.contrib.layers.l2_regularizer(regularization_rate)

loss = cross_entropy_y_mean + regularization(weight_1) + regularization(weight_2)
    
learn_rate = tf.train.exponential_decay(base_learn_rate, global_step, mnist.train.num_examples / batch_size, learn_decay_rate)

optimizer = tf.train.GradientDescentOptimizer(learning_rate = learn_rate).minimize\
        (loss, global_step)
    
train_op = tf.group(optimizer, average_op)

model_result = tf.equal(tf.arg_max(average_y, 1), tf.arg_max(y_, 1))
accurity_model = tf.reduce_mean(tf.cast(model_result, tf.float32))

tf.initialize_all_variables().run()

validation = {x:mnist.validation.images, y_:mnist.validation.labels}
test = {x:mnist.test.images, y_:mnist.test.labels}

sess = tf.InteractiveSession()
for i in range(30000):
    xt, yt = mnist.train.next_batch(batch_size)
    sess.run(train_op, feed_dict = {x:xt, y_:yt})



accurity_value = sess.run(accurity_model, test)
print("test accurity is %f" % accurity_value)
