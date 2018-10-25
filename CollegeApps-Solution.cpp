// Input and output was handled by Hacker Rank
// Testees had to only complete a single function that was passed in: vector<int> collegeSeatsArray, vector<int> studentScoresArray,
// vector<vector<int>> studentCollegePreferencesArray
// The indices of the vector<int> collegeSeatsArray indicate the college number - used to reference the college in the
// studentCollegePreferencesArray. The indices of the studentScoresArray correspond to their corresponding preferences vector in the 
// studentCollegePreferencesArray. The results had to be returned in a vector<int> where the first element the number of seats left,
// and the second element indicated the number of students who didn't go to college
// Each student only gets allocated to one college. 

// Helper functions
int sumElements(vector<int> vec)
{
  int sum = 0;
  for (int i = 0; i < vec.size(); i++)
    sum += vec[i];
  return sum;
}

vector<int> uniqueSort(vector<int> vec)
{
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
  return vec;
}

// The method used in this function ensures that in cases where students have the same scores, the student whose score
// was mentioed earlier in the array will get priority
vector<int> allocate(vector<int> collegeSeatsArray, vector<int> studentScoresArray, vector<vector<int>> studentCollegePreferencesArray)
{
  int seatsLeft = sumElements(collegeSeatsArray);
  int studentsUnallocated = studentScoresArray.size()'
    
  unordered_map<string, vector<vector<int>>> scoresAndPreferences;
  for (int i = 0; i < studentScoresArray.size(); i++)
  {
    if (scoresAndPreferences.find(studentScoresArray[i]) != scoresAndPreferences.end())
      scoresAndPreferences[studentScoresArray[i]] = vector<vector<int>> preferences {studentCollegePreferencesArray[i]};
    else
    {
      vector<vector<int>> preferences = scoresAndPreferences[studentScoresArray[i]];
      preferences.push_back(studentCollegePreferencesArray[i]);
      scoresAndPreferences[studentScoresArray[i]] = preferences;
    }
  }
  
  studentScoresArray = uniqueSort(studentScoresArray);
  
  for (int i = 0; i < studentScoresArray.size(); i++)
  {
    vector<vector<int>> currentStudentPreferences = scoresAndPreferences[studentScoresArray[i]];
    for (int j = 0; j < currentStudentPreferences.size(); j++)
      for (int k = 0; k < currentStudentPreferences[j].size(); k++)
      {
        if (currentStudentPreferences[j][k] > 0)
        {
          currentStudentPreferences[j][k]--;
          studentsUnallocated--;
          seatsLeft--;
          break;
        }
      }
  }
  
  return vector<int> results {seatsLeft, studentsUnallocated};
}
