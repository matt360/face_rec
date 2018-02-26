from PIL import Image, ImageDraw
import face_recognition
import csv
import numpy as np
import array

# to run the application in the terminal: 'python3 find_facial_features_in_picture.py'

# Load the jpg file into a numpy array
image = face_recognition.load_image_file("obama-720p.jpg")

# Find all facial features in all the faces in the image
face_landmarks_list = face_recognition.face_landmarks(image)

print("I found {} face(s) in this photograph.".format(len(face_landmarks_list)))

for face_landmarks in face_landmarks_list:

    # Print the location of each facial feature in this image
    facial_features = [
        'chin',              # 17 * (a ,b)
        'left_eyebrow',      # 5 * (a ,b)
        'right_eyebrow',     # 5 * (a ,b)
        'nose_bridge',       # 4 * (a ,b)
        'nose_tip',          # 5 * (a ,b)
        'left_eye',          # 6 * (a ,b)
        'right_eye',         # 6 * (a ,b)
        'top_lip',           # 12 * (a ,b)
        'bottom_lip'         # 12 * (a ,b)
    ]
    
    for facial_feature in facial_features:
        print("The {} in this face has the following points: {}".format(facial_feature, face_landmarks[facial_feature]))

    for facial_feature in facial_features:
        myFile = open('smile.csv', 'a')
        with myFile:
            writer = csv.writer(myFile)
            writer.writerows(face_landmarks[facial_feature])
        
    for facial_feature in facial_features:
        

    # Let's trace out each facial feature in the image with a line!
    pil_image = Image.fromarray(image)
    d = ImageDraw.Draw(pil_image)

    for facial_feature in facial_features:
        d.line(face_landmarks[facial_feature], width=1)

    pil_image.show()

myData = [["first_name", "second_name", "Grade"],
          ['Alex', 'Brian', 'A'],
          ['Tom', 'Smith', 'B']]

myFile = open('example2.csv', 'w')
with myFile:
    writer = csv.writer(myFile)
    writer.writerows(myData)

# mark picture
#

	# emotions ML:
	# feed picture
	# tell what emotion it is (sad, happy, ect.)
	# recognize facial features
	# save differences in facial features (upper lip - bottom lip, eyebrows - eyes, bottom lip - chin) in an appropriate file: happy file, sad file
	#
	# check for emotion:
	# feed picture
	# recognize facial features
	# compare difference in facial features to the ones in the files (file of happy differences, file of sad differences)
	# output which emotion it fits best (check which set of data is the most similar)
	# tell the programme if it got it right. (print "Did I get it right?")
	# if (Yes): emotion recognized ok - exit
	# else (No): add set of facial features to the specified array (happy, sad, ect.) set of recognizable emotions increases.
