#include "BinarySearchTree.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

const int NUM_VALS = 100;
const int MIN_VAL = 1;
const int MAX_VAL = 200;

std::ofstream myfile;

int randIntBetween(const int min, const int max) {
    int diff = max - min;
    return (rand() % diff) + min;
}

void display(int& anItem){   
	myfile << anItem << "\n ";    
}

int main() {
    BinarySearchTree<int> bst;
    int rand_num;

    std::ofstream outfile;
    std::string filename = "Numbers.txt";
    outfile.open(filename);

    srand(time(0));
    for (int i = 0; i < NUM_VALS; i++) {
        rand_num = randIntBetween(MIN_VAL, MAX_VAL);
        outfile << rand_num << std::endl;
        bst.add(rand_num);
    }

    std::cout << "HEIGHT: " << bst.getHeight() << std::endl;
    
    std::string myfilename1 = "Inorder.txt";
    myfile.open(myfilename1); 
    bst.inorderTraverse(display);
    myfile.close();
    
    std::string myfilename2 = "Preorder.txt";
    myfile.open(myfilename2); 
    bst.preorderTraverse(display);
    myfile.close();
    
    std::string myfilename3 = "Postorder.txt";
    myfile.open(myfilename3); 
    bst.postorderTraverse(display);
    myfile.close();

    return 0;
}