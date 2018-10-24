//Input and output was handled by Hacker Rank
//Testees had to only complete a single function that was passed in the string typed in and would return the output on the faulty keyboard
#incude <cctype.h> //Extra include statement required for islower, toupper etc. functions

string faultyKeyboard(string input)
{
  bool CapsLockOn = false;
  
  for (int i  = 0; input[i] != '\0';)
  {
    if (input[i] == 'a' || input[i] == 'A')
    {
      CapsLockOn = ! CapsLockOn;
      input.erase(i, 1);
      continue;
    }
    
    if (CapsLockOn)
    {   
      if (islower(input[i]))
        input[i] = toupper(input[i]);
      else
        input[i] = tolower(input[i]);
    }
    
    i++;
  }
  
  return input;
}
