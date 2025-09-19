/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:37:18 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/09 11:29:33 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

static void	fillAndReplace(std::ifstream &ifs, std::ofstream &ofs, const std::string &s1, const std::string &s2){
	size_t		startPos;
	size_t		currentPos;

	ifs.seekg(0, std::ios::end);
	std::streampos fileSize = ifs.tellg();
	ifs.seekg(0, std::ios::beg);
	std::string fileContent(fileSize, '\0');
	ifs.read(&fileContent[0], fileSize);

	startPos = 0;
	currentPos = fileContent.find(s1, startPos);
	while (currentPos != std::string::npos){
		ofs << fileContent.substr(startPos, currentPos - startPos);
		ofs << s2;
		startPos = currentPos + s1.size();
		currentPos = fileContent.find(s1, startPos);
	}
	ofs << fileContent.substr(startPos);
	return ;
}

static int	checkArgument(int argument, char *s1){

	if (argument != 4){
		std::cerr << "Wrong number of arguments" << std::endl;
		return 1;
	}
	if (std::string(s1).empty()){
		std::cerr << "Searched string cannot be empty" << std::endl;
		return 1;
	}
	return 0;
}

int	main(int argc, char **argv){

	if (checkArgument(argc, argv[2]))
		return 1;
	std::ifstream	ifs(argv[1]);
	if (!ifs.is_open()){
		std::cerr << "Cannot create input file stream" << std::endl;
		return 1;
	}
	std::string outfile = argv[1];
	outfile += ".replace";
	std::ofstream	ofs(outfile.c_str());
	if (!ofs.is_open()){
		std::cerr << "Cannot create output file stream" << std::endl;
		return 1;
	}
	fillAndReplace(ifs, ofs, argv[2], argv[3]);
	ifs.close();
	ofs.close();
	return(0);
}
