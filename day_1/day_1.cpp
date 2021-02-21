#include <iostream>
#include <string>
#include <fstream>

#define isSum(A, B, SUM)     ((A)+(B) == (SUM) ? (1):(0)) 

// Retrieve the number of lines in our target file
uint16_t getNumLines(std::ifstream &fd, std::string &path)
{
    fd.open(path);
    uint16_t count = 0;
    std::string line;

    if( fd.is_open() )
    {
        while(getline(fd, line))
            count++;
        fd.close();
        return count;
    }
    else
    {
        return -1;
    }
}

// Unused
void bubbleSort(int16_t din[], uint16_t len)
{
    uint16_t i, j;
    int16_t temp;

    for(i=0; i<len-1; i++)
    {
        for(j=0; j<len-i-1; j++)
        {
            if(din[j] > din[j+1])
            {
                temp = din[j+1];
                din[j+1] = din[j];
                din[j] = temp;
            }
        }
    }

}

// Find entries that sum to 2020, then find the product of said entries
void findEntries(int16_t din[], uint16_t len)
{
    uint16_t i, j, offset;

    offset = 1;

    for(i=0; i<len-1; i++)
    {
        for(j=offset; j<len-1; j++)
        {
            if(isSum(din[i], din[j], 2020))
            {
                printf("Entries at index %d & %d sum to 2020\n", i, j);
                printf("Entry values %d, %d\n", din[i], din[j]);
                printf("Product of entries = %d\n", din[i]*din[j]);
            }
        }
        offset++;
    }
}

int main()
{
    std::ifstream fd;
    std::string path = "expense_report.txt";
    std::string line;

    // Create a list with the size of our expense report
    uint16_t len = getNumLines(fd, path);
    int16_t entry[len];
    uint16_t i = 0;

    fd.open(path);

    if(fd.is_open())
    {
        while(getline(fd, line))
        {
            entry[i] = stoi(line);
            i++;
        }
    }

    fd.close();

    // Solve our puzzle by traversing entries list
    findEntries(entry, len);

    return 0;
}