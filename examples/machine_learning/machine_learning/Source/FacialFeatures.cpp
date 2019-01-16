#include "FacialFeatures.h"

FacialFeatures::FacialFeatures()
{
}

FacialFeatures::~FacialFeatures()
{
}

void FacialFeatures::Release()
{
    learning_data.clear();
    weightingsVector.clear();
    chin.clear();
    left_eyebrow.clear();
    right_eyebrow.clear();
    nose_bridge.clear();
    nose_tip.clear();
    left_eye.clear();
    right_eye.clear();
    top_lip.clear();
    bottom_lip.clear();
}

void FacialFeatures::PopulateFacialFeaturesVectors()
{
    // the number of rows to cover all the feautres from one picture is 72 but because there's two colums and they are stored in 1D array we must divide the size 
    // by 144 to get the number of pictures examined.
    std::cout << "STEP: " << STEP << std::endl;
    std::cout << "FacialFeatures::FacialFeatures::learning_data size / STEP: " << FacialFeatures::learning_data.size() / STEP << std::endl;
    // for the same reason we increase 'i' by 144
    int i = 0;
    for (int j = 0; j < FacialFeatures::learning_data.size() / STEP; j++)
    {
        // chin (17) [1] - (number of paired elements for the facial feature) [place in the .csv file + i]
        //for (int i = 0; i < 34; i++) 
        for (; i < (CHIN * 2) + j * STEP; i++) // we need to multiply by 2 to get all the data since it's a 1D array
                                               // create a vector of chin positions
            chin.push_back(FacialFeatures::learning_data.at(i));

        // left eyebrow (5) [18]
        //for (int i = 17 * 2; i < (17 * 2 + 5 * 2); i += 2)
        for (; i < (CHIN * 2 + LEFT_EYEBROW * 2) + j * STEP; i++)
            left_eyebrow.push_back(FacialFeatures::learning_data.at(i));

        // right_eyebrow (5) [23]
        //for (int i = (17 * 2 + 5 * 2); i < (17 * 2 + 5 * 2 + 5 * 2); i += 2)
        for (; i < (CHIN * 2 + LEFT_EYEBROW * 2 + RIGHT_EYEBROW * 2) + j * STEP; i++)
            right_eyebrow.push_back(FacialFeatures::learning_data.at(i));

        // nose_bridge (4) [28]
        //std::cout << "nose bridge" << std::endl;
        //for (int i = (17 * 2 + 5 * 2 + 5 * 2); i < (17 * 2 + 5 * 2 + 5 * 2 + 4 * 2); i += 2)
        for (; i < (CHIN * 2 + LEFT_EYEBROW * 2 + RIGHT_EYEBROW * 2 + NOSE_BRIDGE * 2) + j * STEP; i++)
            nose_bridge.push_back(FacialFeatures::learning_data.at(i));

        // nose_tip (5) [32]
        //std::cout << "nose tip" << std::endl;
        //for (int i = (17 * 2 + 5 * 2 + 5 * 2 + 4 * 2); i < (17 * 2 + 5 * 2 + 5 * 2 + 4 * 2 + 5 * 2); i += 2)
        for (; i < (CHIN * 2 + LEFT_EYEBROW * 2 + RIGHT_EYEBROW * 2 + NOSE_BRIDGE * 2 + NOSE_TIP * 2) + j * STEP; i++)
        {
            nose_tip.push_back(FacialFeatures::learning_data.at(i));
        }

        // left_eye (6) [37]
        //std::cout << "left eye" << std::endl;
        //for (int i = (17 * 2 + 5 * 2 + 5 * 2 + 4 * 2 + 5 * 2); i < (17 * 2 + 5 * 2 + 5 * 2 + 4 * 2 + 5 * 2 + 6 * 2); i += 2)
        for (; i < (CHIN * 2 + LEFT_EYEBROW * 2 + RIGHT_EYEBROW * 2 + NOSE_BRIDGE * 2 + NOSE_TIP * 2 + LEFT_EYE * 2) + j * STEP; i++)
            left_eye.push_back(FacialFeatures::learning_data.at(i));

        // right_eye (6) [43]
        //std::cout << "right eye" << std::endl;
        //for (int i = (17 * 2 + 5 * 2 + 5 * 2 + 4 * 2 + 5 * 2 + 6 * 2); i < (17 * 2 + 5 * 2 + 5 * 2 + 4 * 2 + 5 * 2 + 6 * 2 + 6 * 2); i += 2)
        for (; i < (CHIN * 2 + LEFT_EYEBROW * 2 + RIGHT_EYEBROW * 2 + NOSE_BRIDGE * 2 + NOSE_TIP * 2 + LEFT_EYE * 2 + RIGHT_EYE * 2) + j * STEP; i++)
            right_eye.push_back(FacialFeatures::learning_data.at(i));

        // top_lip (12) [49]
        //std::cout << "top lip" << std::endl;
        //for (; i < (17 * 2 + 5 * 2 + 5 * 2 + 4 * 2 + 5 * 2 + 6 * 2 + 6 * 2 + 12 * 2); i += 2)
        for (; i < (CHIN * 2 + LEFT_EYEBROW * 2 + RIGHT_EYEBROW * 2 + NOSE_BRIDGE * 2 + NOSE_TIP * 2 + LEFT_EYE * 2 + RIGHT_EYE * 2 + TOP_LIP * 2) +
            j * STEP; i++)
            top_lip.push_back(FacialFeatures::learning_data.at(i));

        // bottom_lip (12) [61]
        //std::cout << "bottom lip" << std::endl;
        //for (; i < (17 * 2 + 5 * 2 + 5 * 2 + 4 * 2 + 5 * 2 + 6 * 2 + 6 * 2 + 12 * 2 + 12 *  2); i += 2)
        for (; i < (CHIN * 2 + LEFT_EYEBROW * 2 + RIGHT_EYEBROW * 2 + NOSE_BRIDGE * 2 + NOSE_TIP * 2 + LEFT_EYE * 2 + RIGHT_EYE * 2 + TOP_LIP * 2 +
            BOTTOM_LIP * 2) + j * STEP; i++)
            bottom_lip.push_back(FacialFeatures::learning_data.at(i));
    }
    // check if populating vectors with facial features went ok. The sizes of all vector features added together should equal 'i'
    if (i == chin.size() + left_eyebrow.size() + right_eyebrow.size() + nose_bridge.size() + nose_tip.size() + left_eye.size() + right_eye.size() +
        top_lip.size() + bottom_lip.size())
        std::cout << "Papulating Facial Features Vectors went OK!" << std::endl;
}

void FacialFeatures::PopulateFacialFeaturesVectors(const std::vector<int>& learning_data)
{
    // the number of rows to cover all the feautres from one picture is 72 but because there's two colums and they are stored in 1D array we must divide the size 
    // by 144 to get the number of pictures examined.
    std::cout << "STEP: " << STEP << std::endl;
    std::cout << "learning_data size / STEP: " << learning_data.size() / STEP << std::endl;
    // for the same reason we increase 'i' by 144
    int i = 0;
    for (int j = 0; j < learning_data.size() / STEP; j++)
    {
        // chin (17) [1] - (number of paired elements for the facial feature) [place in the .csv file + i]
        //for (int i = 0; i < 34; i++) 
        for (; i < (CHIN * 2) + j * STEP; i++) // we need to multiply by 2 to get all the data since it's a 1D array
                                               // create a vector of chin positions
            chin.push_back(learning_data.at(i));

        // left eyebrow (5) [18]
        //for (int i = 17 * 2; i < (17 * 2 + 5 * 2); i += 2)
        for (; i < (CHIN * 2 + LEFT_EYEBROW * 2) + j * STEP; i++)
            left_eyebrow.push_back(learning_data.at(i));

        // right_eyebrow (5) [23]
        //for (int i = (17 * 2 + 5 * 2); i < (17 * 2 + 5 * 2 + 5 * 2); i += 2)
        for (; i < (CHIN * 2 + LEFT_EYEBROW * 2 + RIGHT_EYEBROW * 2) + j * STEP; i++)
            right_eyebrow.push_back(learning_data.at(i));

        // nose_bridge (4) [28]
        //std::cout << "nose bridge" << std::endl;
        //for (int i = (17 * 2 + 5 * 2 + 5 * 2); i < (17 * 2 + 5 * 2 + 5 * 2 + 4 * 2); i += 2)
        for (; i < (CHIN * 2 + LEFT_EYEBROW * 2 + RIGHT_EYEBROW * 2 + NOSE_BRIDGE * 2) + j * STEP; i++)
            nose_bridge.push_back(learning_data.at(i));

        // nose_tip (5) [32]
        //std::cout << "nose tip" << std::endl;
        //for (int i = (17 * 2 + 5 * 2 + 5 * 2 + 4 * 2); i < (17 * 2 + 5 * 2 + 5 * 2 + 4 * 2 + 5 * 2); i += 2)
        for (; i < (CHIN * 2 + LEFT_EYEBROW * 2 + RIGHT_EYEBROW * 2 + NOSE_BRIDGE * 2 + NOSE_TIP * 2) + j * STEP; i++)
        {
            nose_tip.push_back(learning_data.at(i));
        }

        // left_eye (6) [37]
        //std::cout << "left eye" << std::endl;
        //for (int i = (17 * 2 + 5 * 2 + 5 * 2 + 4 * 2 + 5 * 2); i < (17 * 2 + 5 * 2 + 5 * 2 + 4 * 2 + 5 * 2 + 6 * 2); i += 2)
        for (; i < (CHIN * 2 + LEFT_EYEBROW * 2 + RIGHT_EYEBROW * 2 + NOSE_BRIDGE * 2 + NOSE_TIP * 2 + LEFT_EYE * 2) + j * STEP; i++)
            left_eye.push_back(learning_data.at(i));

        // right_eye (6) [43]
        //std::cout << "right eye" << std::endl;
        //for (int i = (17 * 2 + 5 * 2 + 5 * 2 + 4 * 2 + 5 * 2 + 6 * 2); i < (17 * 2 + 5 * 2 + 5 * 2 + 4 * 2 + 5 * 2 + 6 * 2 + 6 * 2); i += 2)
        for (; i < (CHIN * 2 + LEFT_EYEBROW * 2 + RIGHT_EYEBROW * 2 + NOSE_BRIDGE * 2 + NOSE_TIP * 2 + LEFT_EYE * 2 + RIGHT_EYE * 2) + j * STEP; i++)
            right_eye.push_back(learning_data.at(i));

        // top_lip (12) [49]
        //std::cout << "top lip" << std::endl;
        //for (; i < (17 * 2 + 5 * 2 + 5 * 2 + 4 * 2 + 5 * 2 + 6 * 2 + 6 * 2 + 12 * 2); i += 2)
        for (; i < (CHIN * 2 + LEFT_EYEBROW * 2 + RIGHT_EYEBROW * 2 + NOSE_BRIDGE * 2 + NOSE_TIP * 2 + LEFT_EYE * 2 + RIGHT_EYE * 2 + TOP_LIP * 2) +
            j * STEP; i++)
            top_lip.push_back(learning_data.at(i));

        // bottom_lip (12) [61]
        //std::cout << "bottom lip" << std::endl;
        //for (; i < (17 * 2 + 5 * 2 + 5 * 2 + 4 * 2 + 5 * 2 + 6 * 2 + 6 * 2 + 12 * 2 + 12 *  2); i += 2)
        for (; i < (CHIN * 2 + LEFT_EYEBROW * 2 + RIGHT_EYEBROW * 2 + NOSE_BRIDGE * 2 + NOSE_TIP * 2 + LEFT_EYE * 2 + RIGHT_EYE * 2 + TOP_LIP * 2 +
            BOTTOM_LIP * 2) + j * STEP; i++)
            bottom_lip.push_back(learning_data.at(i));
    }
    // check if populating vectors with facial features went ok. The sizes of all vector features added together should equal 'i'
    if (i == chin.size() + left_eyebrow.size() + right_eyebrow.size() + nose_bridge.size() + nose_tip.size() + left_eye.size() + right_eye.size() +
        top_lip.size() + bottom_lip.size())
        std::cout << "Papulating Facial Features Vectors went OK!" << std::endl;
}

void FacialFeatures::DisplayFacialFeaturesVectors()
{
    // 'chin', 17 * (a, b)
    std::cout << "chin " << "size: " << chin.size() % 17 << std::endl; // 0 means its okay
    for (int i = 0; i < 17 * 2; i += 2)
        std::cout << chin.at(i) << ", " << chin.at(i + 1) << std::endl;
    // 'left_eyebrow', 5 * (a, b)
    std::cout << "left_eyebrow" << "size: " << left_eyebrow.size() % 5 << std::endl;
    for (int i = 0; i < 5 * 2; i += 2)
        std::cout << left_eyebrow.at(i) << ", " << left_eyebrow.at(i + 1) << std::endl;
    // 'right_eyebrow', 5 * (a, b)
    std::cout << "right_eyebrow" << "size: " << left_eyebrow.size() % 5 << std::endl;
    for (int i = 0; i < 5 * 2; i += 2)
        std::cout << right_eyebrow.at(i) << ", " << right_eyebrow.at(i + 1) << std::endl;
    // 'nose_bridge', 4 * (a, b)
    std::cout << "nose_bridge" << "size: " << nose_bridge.size() % 4 << std::endl;
    for (int i = 0; i < 4 * 2; i += 2)
        std::cout << nose_bridge.at(i) << ", " << nose_bridge.at(i + 1) << std::endl;
    // 'nose_tip', 5 * (a, b)
    std::cout << "nose_tip" << "size: " << nose_tip.size() % 5 << std::endl;
    for (int i = 0; i < 5 * 2; i += 2)
        std::cout << nose_tip.at(i) << ", " << nose_tip.at(i + 1) << std::endl;
    // 'left_eye', 6 * (a, b)
    std::cout << "left_eye" << "size: " << left_eye.size() % 6 << std::endl;
    for (int i = 0; i < 6 * 2; i += 2)
        std::cout << left_eye.at(i) << ", " << left_eye.at(i + 1) << std::endl;
    // 'right_eye', 6 * (a, b)
    std::cout << "right_eye" << "size: " << right_eye.size() % 6 << std::endl;
    for (int i = 0; i < 6 * 2; i += 2)
        std::cout << right_eye.at(i) << ", " << right_eye.at(i + 1) << std::endl;
    // 'top_lip', 12 * (a, b)
    std::cout << "top_lip" << "size: " << top_lip.size() % 12 << std::endl;
    for (int i = 0; i < 12 * 2; i += 2)
        std::cout << top_lip.at(i) << ", " << top_lip.at(i + 1) << std::endl;
    // 'bottom_lip', 12 * (a, b)
    std::cout << "bottom_lip" << "size: " << bottom_lip.size() % 12 << std::endl;
    for (int i = 0; i < 12 * 2; i += 2)
        std::cout << bottom_lip.at(i) << ", " << bottom_lip.at(i + 1) << std::endl;
}

void FacialFeatures::CalculateEmotionWeightings(const char* file_name)
{
    // std::ios_bas::app - all output operations happen at the end of the file, appending to its existing contents.
    weightingsFile.open(file_name, std::ios_base::app);

    // data in the facial_recognition algorithm has a layout:
    /*
    'chin',          17 * (a, b)
    'left_eyebrow',  5 * (a, b)
    'right_eyebrow', 5 * (a, b)
    'nose_bridge',   4 * (a, b)
    'nose_tip',      5 * (a, b)
    'left_eye',      6 * (a, b)
    'right_eye',     6 * (a, b)
    'top_lip',       12 * (a, b)
    'bottom_lip'     12 * (a, b)
    */
    // in order to extract facial features we need to take the appropriate pairs of data and subtrack them so we can get:
    // a distance of the left_eyebrow from the left_eye :
    // 5 - 6  = (5 pairs of numbers) - (6 pairs of numbers) = (even - odd) + ... + (even - odd) = 
    // (0 - 1) + (2 - 3) + (4 - 5) + (6 - 7) + (8 - 9) = -(weight value for the emotion)
    /*
    const int CHIN = 17;			 // 17 * (a, b) - number of variables for a facial feature is 34 (17 * 2 variables) - reason: it's stored in a 1D array
    const int LEFT_EYEBROW = 5;      //  5 * (a, b)
    const int RIGHT_EYEBROW = 5;     //  5 * (a, b)
    const int NOSE_BRIDGE = 4;       //  4 * (a, b)
    const int NOSE_TIP = 5;          //  5 * (a, b)
    const int LEFT_EYE = 6;          //  6 * (a, b)
    const int RIGHT_EYE = 6;         //  6 * (a, b)
    const int TOP_LIP = 12;          // 12 * (a, b)
    const int BOTTOM_LIP = 12;       // 12 * (a, b)
    const int LIP_DIST = 12;
    const int EYE_EYEBROW_DIST = 5;
    const int NOSE_DIST = 4;
    */

    // append emotion weighted values for smile into the file
    //for (int i = 1; i < left_eyebrow.size() - 1; i++)
    //{
    //	// (5 - 6)
    //	// at the beginning we don't have to adjust for vector size difference
    //	if (i == 1 || i == 2)
    //		left_eyebrow_left_eye_distance.push_back(left_eyebrow.at(i - 1) - left_eye.at(i - 1));
    //	// do reduction only if 'i' is dividable by 3
    //	else if (i % 3 == 0 && i % 4 != 0 && i % 6 != 0)
    //		left_eyebrow_left_eye_distance.push_back(left_eyebrow.at(i - 1) - (left_eye.at(i) - left_eye.at(i - 1))); // we add one to acomodate for different vector sizes
    //	else
    //		left_eyebrow_left_eye_distance.push_back(left_eyebrow.at(i - 1) - left_eye.at(i));
    //}
    for (int i = 0; i < left_eyebrow.size(); i++)
    {
        // (5 - 6)
        // at the beginning we don't have to adjust for vector size difference
        weightingsVector.push_back(left_eyebrow.at(i) - left_eye.at(i + 1));
        weightingsFile << left_eyebrow.at(i) - left_eye.at(i + 1) << std::endl;
    }

    // a distance of the right_eyebrow from the right_eye: 
    for (int i = 0; i < right_eyebrow.size(); i++)
    {
        // (5 - 6)
        weightingsVector.push_back(right_eyebrow.at(i) - right_eye.at(i + 1));
        weightingsFile << right_eyebrow.at(i) - right_eye.at(i + 1) << std::endl;
    }

    // a distance of the top_lip from the bottom_lip:
    for (int i = 0; i < top_lip.size(); i++)
    {
        // (12 - 12)
        weightingsVector.push_back(top_lip.at(i) - bottom_lip.at(i));
        weightingsFile << top_lip.at(i) - bottom_lip.at(i) << std::endl;
    }

    // a distance from the nose tip to the nose bridge:
    for (int i = 0; i < nose_bridge.size(); i++)
    {
        // (5 - 4)
        weightingsVector.push_back(nose_bridge.at(i) - nose_tip.at(i + 1));
        weightingsFile << nose_bridge.at(i) - nose_tip.at(i + 1) << std::endl;
    }

    // if (emv != any set of values in the file)
    //for (auto it_0 = left_eyebrow_left_eye_distance.begin(); it != left_eyebrow_left_eye_distance.end(); ++it)
    //	for (auto it_1 = right_eyebrow_right_eye_distance.begin(); it != right_eyebrow_right_eye_distance.end(); ++it)
    //		for (auto it_2 = top_lip_bottom_lip_distance.begin(); it != top_lip_bottom_lip_distance.end(); ++it)
    //			for (auto it_3 = nose_tip_nose_bridge_distance.begin(); it != nose_tip_nose_bridge_distance.end(); ++it)
    //			{
    //				m_SmileWeightings << 
    //				*it_0 << ',' << 
    //				*it_1 << ',' << 
    //				*it_2 << ',' << 
    //				*it_3 << std::endl; // ',' - makes it go to the next cell in the .csv file
    //			}
    weightingsFile.close();
}

void FacialFeatures::CalculateEmotionWeightings()
{
    for (int i = 0; i < left_eyebrow.size(); i++)
    {
        // (5 - 6)
        // at the beginning we don't have to adjust for vector size difference
        weightingsVector.push_back(left_eyebrow.at(i) - left_eye.at(i + 1));
    }

    // a distance of the right_eyebrow from the right_eye: 
    for (int i = 0; i < right_eyebrow.size(); i++)
    {
        // (5 - 6)
        weightingsVector.push_back(right_eyebrow.at(i) - right_eye.at(i + 1));
    }

    // a distance of the top_lip from the bottom_lip:
    for (int i = 0; i < top_lip.size(); i++)
    {
        // (12 - 12)
        weightingsVector.push_back(top_lip.at(i) - bottom_lip.at(i));
    }

    // a distance from the nose tip to the nose bridge:
    for (int i = 0; i < nose_bridge.size(); i++)
    {
        // (5 - 4)
        weightingsVector.push_back(nose_bridge.at(i) - nose_tip.at(i + 1));
    }
}

int FacialFeatures::GenerateLearningVectorFromFile(const char* emotion_learning_file)
{
    // file to store the .csv 
    FILE *file;
    // two chars to read from two columns in each row in the .csv file
    char str1[10], str2[10];

    // open the .csv file to read the data
    file = fopen(emotion_learning_file, "r");
    // check if the file was opened correctly
    if (NULL == file)
    {
        printf("\nError in opening file.");
        return 0;
    }

    // read data into a vector from a .csv file with two columns
    while (EOF != fscanf(file, " %[^,], %s ", str1, str2))
    {
        learning_data.push_back(std::stoi(str1));
        learning_data.push_back(std::stoi(str2));
    }
    // close the file after reading the data into the vector
    fclose(file);
    
    return 0;
}

void FacialFeatures::Learn(const char* learning_file_name, const char* weightings_file_name)
{
    GenerateLearningVectorFromFile(learning_file_name);

    PopulateFacialFeaturesVectors();
    CalculateEmotionWeightings(weightings_file_name);
}

void FacialFeatures::Learn(const char* learning_file_name)
{
    GenerateLearningVectorFromFile(learning_file_name);

    PopulateFacialFeaturesVectors();
    CalculateEmotionWeightings();
}