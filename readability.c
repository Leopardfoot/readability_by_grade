#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string words);
int count_words(string quote);
int count_sentences(string quote);
float get_l(int letters, int words);
float get_s(int sentences, int words);

int main(void)
{
    // Get input text from user
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    //Troubleshooting printf functions to check the values of letters, numbers, and words.
    /*printf("%i letter(s)\n", letters);
    printf("%i word(s)\n", words);
    printf("%i sentence(s)\n", sentences);*/

    float L = get_l(letters, words);
    float S = get_s(sentences, words);
    //Formula for the Coleman Liau index of school grade reading levels. Will be an integer to correspond with grade values.
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);

    //Determine reading level output depending on the value of grade.
    if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int count_letters(string words)
{
    // Counts the letters in the inputted text string based on their ASCII values.
    int letters = 0;
    for (int i = 0; i < strlen(words); i++)
    {
        if ((int) words[i] <= 90 && (int) words[i] >= 65)
        {
            letters++;
        }
        else if ((int) words[i] < 123 && (int) words[i] > 96)
        {
            letters++;
        }
    }

    return letters;
}

int count_words(string quote)
{
    //Counts the words in the inputted text string by considering groups of characters seperated by spaces as single words. Checkes a space by looking at the ASCII value as well as counting the last word of a non zero string.
    int words = 0;
    for (int i = 0; i < strlen(quote); i++)
    {
        if ((int) quote[i] == 32)
        {
            words++;
        }
        else if (i == strlen(quote) - 1 && strlen(quote) != 0)
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string quote)
{
    //Counts the sentences in the inputted text string by considering any punctuation of . ? or ! to denote the end of he sentence. There are cases where these do not actually denote the end of a sentence but for this function's
    //purposes we shall ignore those.
    int sentences = 0;
    for (int i = 0; i < strlen(quote); i++)
    {
        if (quote[i] == '.' || quote[i] == '?' || (int) quote[i] == '!')
        {
            sentences++;
        }
    }
    return sentences;
}

//function which gets the average letters per 100 words
float get_l(int letters, int words)
{
    float ans = ((float) letters / (float) words) * 100;
    return ans;
}

//function which outputs the average sentences per 100 words.
float get_s(int sentences, int words)
{
    float ans = ((float) sentences / (float) words) * 100;
    return ans;
}