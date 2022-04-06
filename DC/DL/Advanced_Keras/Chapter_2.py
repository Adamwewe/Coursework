"""
Making a reusable embedded model
"""

# Imports
from keras.layers import Input, Embedding, Flatten
from keras.models import Model

# Create an input layer for the team ID
teamid_in = Input(shape=(1,))

# Lookup the input in the team strength embedding layer
strength_lookup = team_lookup(teamid_in)

# Flatten the output
strength_lookup_flat = Flatten()(strength_lookup)

# Combine the operations into a single, re-usable model
team_strength_model = Model(teamid_in, strength_lookup_flat, name='Team-Strength-Model')

"""
Create shared input
"""
# Load the input layer from keras.layers
from keras.layers import Input

# Input layer for team 1
team_in_1 = Input((1,), name="Team-1-In")

# Separate input layer for team 2
team_in_2 = Input((1,), name="Team-2-In")


"""
Merge layers

"""

# Imports
from keras.layers import Subtract
from keras.models import Model

# Subtraction layer from previous exercise
score_diff = Subtract()([team_1_strength, team_2_strength])

# Create the model
model = Model([team_in_1,team_in_2], score_diff)

# Compile the model
model.compile(optimizer="adam", loss="mean_absolute_error")


"""
Predicting multiple inputs

Key here: nb of inputs = len(input list)
we do data prerprocessing as part of the model itself 

"""

# Here is how we fit the models:

# Get the team_1 column from the regular season data
input_1 = games_season["team_1"]

# Get the team_2 column from the regular season data
input_2 = games_season["team_2"]

# Fit the model to input 1 and 2, using score diff as a target
model.fit([input_1,input_2],
          y= games_season["score_diff"],
          epochs=1,
          batch_size=2048,
          validation_split=0.1,
          verbose=True)
          
# Now we evalaute:

# Get team_1 from the tournament data
input_1 = games_tourney["team_1"]

# Get team_2 from the tournament data
input_2 = games_tourney["team_2"]

# Evaluate the model using these inputs
print(model.evaluate([input_1, input_2], games_tourney["score_diff"], verbose=False))
          




