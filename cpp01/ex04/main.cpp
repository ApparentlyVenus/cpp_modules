/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 21:44:02 by odana             #+#    #+#             */
/*   Updated: 2025/08/07 23:16:44 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

std::string	readFile(std::ifstream& infile)
{
	std::string	line;
	std::string	content;
    while (std::getline(infile, line))
	{
		if (!content.empty())
			content += "\n";
		content += line;
	}
	infile.close();
	return (content);
}

std::string	replaceString(std::string& content, std::string& s1, std::string& s2)
{
	std::string	result;
	size_t 		pos;
	size_t 		found;
	
	if (s1.empty())
		return (content);

	pos = 0;
	while ((found = content.find(s1, pos)) != std::string::npos) 
	{
	    result += content.substr(pos, found - pos);
	    result += s2;
	    pos = found + s1.length();
	}
	result += content.substr(pos);
	return (result);
}

int	main(int argc, char **argv)
{
    if (argc != 4)
	{
		std::cerr << "Incorrect format: ./replace <filename> <s1> <s2>" << std::endl;
		return (1);
	}
    
    std::string		filename = argv[1];
	std::string		outfileName = filename + ".replace";
    std::string		s1 = argv[2];
    std::string		s2 = argv[3];
    
    std::ifstream	infile(filename.c_str());
	std::string		content;
    if (infile.is_open())
		content = readFile(infile);
	else
	{
		std::cerr << "Unable to open file" << std::endl;
		return (1);
	}
	
	std::ofstream	outfile(outfileName.c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Unable to create outfile" << std::endl;
		return (1);
	}

	std::string 	result = replaceString(content, s1, s2);
	outfile << result;
	outfile.close();
    return (0);
}