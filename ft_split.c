#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function for count the total splits:
int	count_arrays(char *str, char c)
{
	int word;
	int	i;

	word = 0;
	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] == c)
			word++;
		i++;
	}
	return (word);
}

// Function FREE
void *free_mem(void *p)
{
    free(p);
    return (NULL);
}

// Function split:

char	**ft_split(char *str, char c)
{
	char	**splits;
	int	arr_pointer;
	int	arr_idx;
	int	str_idx;
	int	start_idx;

	splits = (char **) malloc((count_arrays(str, c) + 1) * sizeof(char *));
	if (!splits)
        return (free_mem(splits));

	// Declaring INDEXES that we're gonna working with;

    arr_pointer = 0; //splits idx;
	arr_idx = 0; // *splits idx;
	str_idx = 0; // argument str idx;
	start_idx = 0; // creating string first idx;
	
    while (str[str_idx] != '\0')
	{
        // FIRST FUNCTION TO DIVIDE:
		
        if (str[str_idx] == c && str_idx == 0)  // if delimiter is the first index, we should return an empty string;
        {
            splits[arr_pointer] = (char *) malloc(((str_idx - start_idx) + 1) * sizeof(char));
            
            // Checking if it's created and if it's not, we'll free it;
            
            if (!splits[arr_pointer])
                return (free_mem(splits[arr_pointer]));
            
            // Setting the null char of the empty string;
            
            splits[arr_pointer][arr_idx] = '\0';
            
            // moving the starting index in the next position
            
            start_idx += 1;
            
            // moving to the next string;
            
            arr_pointer++;
        }

        // SECOND FUNCTION TO DIVIDE
        
        // if delimiter is any position inside of the given string
		if (str[str_idx] == c && str_idx > 0) 
        {
            // creating the new string with length of the given string index - start index + null char
			
            splits[arr_pointer] = (char *) malloc(((str_idx - start_idx) + 1) * sizeof(char));
            if (!splits[arr_pointer])
                return (free_mem(splits[arr_pointer]));
            
            // starting adding values to the new created string
			
            while (start_idx < str_idx)
				splits[arr_pointer][arr_idx++] = str[start_idx++];
			splits[arr_pointer][arr_idx] = '\0';

            // moving the starting index to the next character after the delimiter;
            
            start_idx++;

            // increasing the index of string pointers

            arr_pointer++;
		}
        
        // setting the new created strings index to 0 after every allocation
        
        arr_idx = 0;
		
        // walking within the given strings looking for delimiter

        str_idx++;
	}
    
    // THIRD FUNCTION TO DIVIDE:
    // creating the last string of the map when the given string index is the null char
    
    splits[arr_pointer] = (char *) malloc(((str_idx - start_idx) + 1) * sizeof(char));
    if (!splits[arr_pointer])
        return (free_mem(splits[arr_pointer]));
    while (start_idx < str_idx)
        splits[arr_pointer][arr_idx++] = str[start_idx++];
    splits[arr_pointer][arr_idx] = '\0';
    // Set END Character of array;
    splits[arr_pointer + 1] = '\0';
	return (splits);
}

int	main(void)
{
	char	*str_to_split = "am ajuns acasa si fac supa";
	char	**split;

	split = ft_split(str_to_split, 's');
	while (*split)
	{
		printf("%s\n", *split);
		split++;
	}
	while (*split)
		free(*split);
	return (0);
}
