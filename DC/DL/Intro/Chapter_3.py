## Chapter 3

"""
There are multiple ways to build a model in Keras:
    - Squential
    - 

"""


# Import necessary modules
import keras
from keras.layers import Dense
from keras.models import Sequential

# Save the number of columns in predictors: n_cols
n_cols = predictors.shape[1]

# Set up the model: model
model = Sequential()

# Add the first layer
model.add(Dense(50, activation="relu", input_shape=(n_cols,)))

# Add the second layer
model.add(Dense(32, activation="relu", input_shape=(n_cols,)))


# Add the output layer
model.add(Dense(1, input_shape=(n_cols,)))


"""
Now that we created a model, we need to compile it to set:
    - An optimizer
    - Error Metric
    - etc.
"""


# Import necessary modules
import keras
from keras.layers import Dense
from keras.models import Sequential

# Specify the model
n_cols = predictors.shape[1]
model = Sequential()
model.add(Dense(50, activation='relu', input_shape = (n_cols,)))
model.add(Dense(32, activation='relu'))
model.add(Dense(1))

# Compile the model

model.compile(optimizer="adam", loss="mean_squared_error")

# Verify that model contains information from compiling
print("Loss function: " + model.loss)

# Fit the model
model.fit(predictors, target)


# Import necessary modules
import keras
from keras.layers import Dense
from keras.models import Sequential
from keras.utils import to_categorical

# Convert the target to categorical: target
target = to_categorical(df.survived)

# Set up the model
model = Sequential()

# Add the first layer
model.add(Dense(32, activation='relu', input_shape=(n_cols,)))

# Add the output layer
model.add(Dense(2, activation='softmax'))

# Compile the model
model.compile(optimizer='sgd', 
              loss='categorical_crossentropy', 
              metrics=['accuracy'])

# Fit the model
model.fit(predictors, target)


# Make predictions


# Calculate predictions: predictions
predictions = pred_data.predict()

# Calculate predicted probability of survival: predicted_prob_true
predicted_prob_true = predictions[,1]
# print predicted_prob_true
print(predicted_prob_true)




