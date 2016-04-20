#include "parser.h"

parser::parser()
{

}

parser::~parser()
{

}

void parser::checkFile(ifstream &in, string &filename)
{
    cout << "Enter the filename of the file you wish to open : ";
    getline(cin, filename);
    in.open(filename+".txt");
    if(in.fail())
    {
        cout << "File does not exist!\n";
        exit(0);
    }
    cout << "File open!\n";
    in.close();
}

void parser::getText(ifstream &in, string filename, torchard& orchard)
{

    string line, word, word2;
    int pos, paragraphs = 1, lines = 0, words = 0, sentences = 0, syllables = 0;
    in.open("warandpeace.txt");

    stringstream ss;

    while(!in.eof())
    {        
        pos = 0;
        getline(in,line);
        if(line == "")
        {
            ++paragraphs;
            lines = 0;
        }
        else
        {
            lines++;
            while((pos = line.find_first_not_of(" ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!:.?\'")) < string::npos)
                line[pos] = ' ';
            while((pos = line.find_first_of(":.?!")) < string::npos)
            {
                sentences++;
                line.erase(pos,1);
                line.insert(pos, " ");
            }

            ss << line;
            while(ss >> word)
            {
                word2 = "";
                if((pos = word.find("\'"))<string::npos)
                {
                    if(!pos)
                        word.erase(pos,1);
                    else
                        word2 = contraction(word);
                }
                if(word.length()>0)
                {
                    word[0] = toupper(word[0]);
                    orchard.insert(word, paragraphs, lines);
                    words++;
                    for(pos = 0; pos < word.length(); ++pos)
                    {
                        if(toupper(word[pos]) == 'A' || toupper(word[pos]) == 'E' || toupper(word[pos]) == 'I'
                           || toupper(word[pos]) == 'O' || toupper(word[pos]) == 'U' ||toupper(word[pos]) == 'Y')
                            syllables++;
                    }
                }
                if(word2.length()>0)
                {
                    orchard.insert(word2, paragraphs, lines);
                    words++;
                    for(pos = 0; pos < word2.length(); ++pos)
                    {
                        if(toupper(word2[pos]) == 'A' || toupper(word2[pos]) == 'E' || toupper(word2[pos]) == 'I'
                           || toupper(word2[pos]) == 'O' || toupper(word2[pos]) == 'U' ||toupper(word2[pos]) == 'Y')
                            syllables++;
                    }
                }

            }
            ss.clear();
        }
    }
    orchard.paragraphs = paragraphs;
    orchard.words = words;
    orchard.sentences = sentences;
    orchard.syllables = syllables;
    in.close();
}

string parser::contraction(string word)
{
    if (word.find("n\'t") != string::npos)
    {
        if(word == "Won't")
            word = "Will";
        else if (word == "Can't")
            word = "Can";
        else if (word == "Shan't")
            word = "Shall";
        else
            word = word.erase(word.find("\'")-1, word.length()-word.find("\'")+1);
        return "Not";
    }
    else if (word.find("O\'") != string::npos)
    {
        word = "Of";
        return "";
    }
    else if (word.find("\'s")!= string::npos)
    {
        word.erase(word.find("\'"), word.length()-word.find("\'"));
        if(word == "It" || word == "Where" || word == "One")
            return "Is";
        else
            return "";
    }
    else if (word.find("\'re")!= string::npos)
    {
        word.erase(word.find("\'"), word.length()-word.find("\'"));
        return "Are";
    }
    else if (word.find("\'ll")!= string::npos)
    {
        word.erase(word.find("\'"), word.length()-word.find("\'"));
        return "Will";
    }
    else if (word.find("\'d")!= string::npos)
    {
        word.erase(word.find("\'"), word.length()-word.find("\'"));
        return "Would";
    }
    else if (word.find("\'ve")!= string::npos)
    {
        word.erase(word.find("\'"), word.length()-word.find("\'"));
        return "Have";
    }
    else
    {
        word.erase(word.find("\'"), 1);
        word[0] = toupper(word[0]);
        return "";
    }
}
