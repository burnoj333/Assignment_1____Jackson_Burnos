The code begins by testing for the number of elements in the array, making sure all 100 integers were read. In my code I am calling and outputting the .getSize() function which just returns numItems.

The first test is for the first function. This calls .isPresent(value) and returns the index if present and -1 if not. It asks first for a valid value in the array (1-100) and will output the index it is at. The code also asks for a bad value (<1 or >100) to show that it returns -1 if its not in there.

The second test asks for an index to modify and what to modify it with. it then calls .modIndex(index,value) with these inputs. This function has print statements within outputting/returning the original value at the index with the new one

The third test asks for a value to add to the end of the array. I wrote my own ".addEnd(value)" function. To show this works a print statement is included which outputs the value at array[numItems-1]. Note: it does not check if your input is an integer. 

The last test asks for in index to delete. It does not check for valid index so enter something valid. It removes it an shifts everything over. 

I decided to make my own array class. I know we could not use vectors but making my own array class which can dynamically resize itself is essentially using vectors. It does help me to see the limitations of arrays, along with how vectors work and what situations they are more useful in than arrays. 
<img width="1920" height="1200" alt="Screenshot (48)" src="https://github.com/user-attachments/assets/efaf87cc-84b2-451a-b212-cf7701e69e7c" />

