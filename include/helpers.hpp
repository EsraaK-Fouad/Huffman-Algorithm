#ifndef SBE201_WORDCOUNT_MAPS_HELPERS_HPP
#define SBE201_WORDCOUNT_MAPS_HELPERS_HPP

#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <iostream>

std::string getFileFirstLine( const std::string &filePath )
{
    std::ifstream f( filePath );
    std::string line;

    if( f )
        std::getline( f , line );

    else std::cout << "Failed to open file:" << filePath << std::endl;
    return line;
}

std::vector< std::string > split( const std::string &s , char delim )
{
    std::stringstream ss( s );
    std::vector< std::string > tokens;
    std::string token;
    while( std::getline( ss , token , delim ))
        tokens.push_back( token );
    return tokens;
}


std::vector< std::string > getFileWords( const std::string &filePath )
{
    std::ifstream f( filePath );
    std::vector< std::string > words;
    std::string line;
    if( f )
    {
        while( std::getline( f , line ))
        {
            line.erase( std::remove_if( line.begin(),
                                        line.end(),
                                         [](char c)
                                         { return c==','||c=='.'|| c=='!' || c == '"'; }), line.end());

            std::transform( line.begin(),
                            line.end(),
                            line.begin(),
                           [] (unsigned char c) { return std::tolower(c); });

            for( const auto &word : split( line , ' ' ) )
                words.push_back( word );
        }
    }
    else std::cout << "Failed to open file:" << filePath << std::endl;
    return words;
}


#endif //SBE201_WORDCOUNT_MAPS_HELPERS_HPP