/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: teo
 *
 * Created on December 21, 2016, 4:53 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

/*
 * 
 */
int main(int argc, char **argv) {
	std::ifstream file("Read.txt");
    std::string str; 
    while (std::getline(file, str))
    {
        cout << str;
    }

	return 0;
}

