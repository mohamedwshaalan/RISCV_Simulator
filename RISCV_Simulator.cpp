#include <iostream>
#include "stdlib.h"
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void decimalToBinary(int n)
{
    int binaryNumber[32];
    int i = 0;
    while (n > 0) {
        binaryNumber[i] = n % 2;
        n = n / 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--)
        cout << binaryNumber[j];
}

void decimalToHex(int n) {

    char hexadecimalNumber[100];
    int i = 0;
    while (n != 0) {

        int temp = 0;
        temp = n % 16;

        if (temp < 10) {
            hexadecimalNumber[i] = temp + 48;
            i++;
        }
        else {
            hexadecimalNumber[i] = temp + 55;
            i++;
        }
        n = n / 16;
    }

    for (int j = i - 1; j >= 0; j--)
        cout << hexadecimalNumber[j];

}

int registertoInt(string registervalue) {

    if (registervalue == "x1") {
        return 1;
    }
    if (registervalue == "x2") {
        return 2;
    }
    if (registervalue == "x3") {
        return 3;
    }
    if (registervalue == "x4") {
        return 4;
    }
    if (registervalue == "x5") {
        return 5;
    }
    if (registervalue == "x6") {
        return 6;
    }
    if (registervalue == "x7") {
        return 7;
    }
    if (registervalue == "x8") {
        return 8;
    }
    if (registervalue == "x9") {
        return 9;
    }
    if (registervalue == "x10") {
        return 10;
    }
    if (registervalue == "x11") {
        return 11;
    }
    if (registervalue == "x12") {
        return 12;
    }
    if (registervalue == "x13") {
        return 13;
    }
    if (registervalue == "x14") {
        return 14;
    }
    if (registervalue == "x15") {
        return 15;
    }
    if (registervalue == "x16") {
        return 16;
    }
    if (registervalue == "x17") {
        return 17;
    }
    if (registervalue == "x18") {
        return 18;
    }
    if (registervalue == "x19") {
        return 19;
    }
    if (registervalue == "x20") {
        return 20;
    }
    if (registervalue == "x21") {
        return 21;
    }
    if (registervalue == "x22") {
        return 22;
    }
    if (registervalue == "x23") {
        return 23;
    }
    if (registervalue == "x24") {
        return 24;
    }
    if (registervalue == "x25") {
        return 25;
    }
    if (registervalue == "x26") {
        return 26;
    }
    if (registervalue == "x27") {
        return 27;
    }
    if (registervalue == "x28") {
        return 28;
    }
    if (registervalue == "x29") {
        return 29;
    }
    if (registervalue == "x30") {
        return 30;
    }
    if (registervalue == "x31") {
        return 31;
    }
    return  0;
}

void simulator(string instructionword, int registers[], int pc, vector<int> memory) {

    int currentpc = pc - 4;

    int twoLetterRD = registertoInt(instructionword.substr(3, instructionword.find(' ')));
    int twoLetterRS1 = registertoInt(instructionword.substr(7, instructionword.find(' ')));
    int twoLetterRS2 = registertoInt(instructionword.substr(11, instructionword.find(' ')));
    int threeLetterRD = registertoInt(instructionword.substr(4, instructionword.find(' ') - 1));
    int threeLetterRS1 = registertoInt(instructionword.substr(8, instructionword.find(' ') - 1));
    int threeLetterRS2 = registertoInt(instructionword.substr(12, instructionword.find(' ') - 1));
    int fourLetterRD = registertoInt(instructionword.substr(5, instructionword.find(' ') - 2));
    int fourLetterRS1 = registertoInt(instructionword.substr(9, instructionword.find(' ') - 2));
    int fourLetterRS2 = registertoInt(instructionword.substr(13, instructionword.find(' ') - 2));
    int fiveLetterRD = registertoInt(instructionword.substr(6, instructionword.find(' ') - 3));
    int fiveLetterRS1 = registertoInt(instructionword.substr(10, instructionword.find(' ') - 3));
    int fiveLetterRS2 = registertoInt(instructionword.substr(14, instructionword.find(' ') - 3));
    int instructionlength = instructionword.length();
    int immediatevalue = ((int)instructionword[instructionlength - 1] - 48);





    if (instructionword.substr(0, instructionword.find(' ')) == "add") { //ADD

        registers[threeLetterRD] = registers[threeLetterRS1] + registers[threeLetterRS2];




    }
    if (instructionword.substr(0, instructionword.find(' ')) == "sub") { //SUB

        registers[threeLetterRD] = registers[threeLetterRS1] - registers[threeLetterRS2];



    }
    if (instructionword.substr(0, instructionword.find(' ')) == "sll") { //SLL

        registers[threeLetterRD] = registers[threeLetterRS1] << threeLetterRS2;


    }
    if (instructionword.substr(0, instructionword.find(' ')) == "slt") { //SLT

        if (registers[threeLetterRS1] < registers[threeLetterRS2]) {
            registers[threeLetterRD] = 1;
        }
        else {
            registers[threeLetterRD] = 0;
        }


    }
    if (instructionword.substr(0, instructionword.find(' ')) == "sltu") { //SLTU

        if ((unsigned int)registers[threeLetterRS1] < (unsigned int)registers[threeLetterRS2]) {
            registers[threeLetterRD] = 1;
        }
        else {
            registers[threeLetterRD] = 0;
        }
    }
    if (instructionword.substr(0, instructionword.find(' ')) == "xor") { //XOR

        registers[threeLetterRD] = registers[threeLetterRS1] ^ registers[threeLetterRS2];

    }

    if (instructionword.substr(0, instructionword.find(' ')) == "srl") { //SRL

        registers[threeLetterRD] = (unsigned int)registers[threeLetterRS1] >> threeLetterRS2;

    }
    if (instructionword.substr(0, instructionword.find(' ')) == "sra") { //SRA

        registers[threeLetterRD] = registers[threeLetterRS1] >> threeLetterRS2;

    }
    if (instructionword.substr(0, instructionword.find(' ')) == "or") { //OR

        registers[twoLetterRD] = (registers[twoLetterRS1] | registers[twoLetterRS2]);

    }
    if (instructionword.substr(0, instructionword.find(' ')) == "and") { //AND

        registers[threeLetterRD] = registers[threeLetterRS1] & threeLetterRS2;


    }
    if (instructionword.substr(0, instructionword.find(' ')) == "addi") { //ADDI


        registers[fourLetterRD] = registers[fourLetterRS1] + immediatevalue;



    }
    if (instructionword.substr(0, instructionword.find(' ')) == "slti") { //SLTI

        if (registers[fourLetterRS1] < immediatevalue) {
            registers[fourLetterRD] = 1;
        }
        else {
            registers[fourLetterRD] = 0;
        }


    }
    if (instructionword.substr(0, instructionword.find(' ')) == "sltiu") { //SLTIU

        if ((unsigned int)registers[fiveLetterRS1] < (unsigned int)immediatevalue) {
            registers[fiveLetterRD] = 1;
        }
        else {
            registers[fiveLetterRD] = 0;
        }


    }
    if (instructionword.substr(0, instructionword.find(' ')) == "xori") { //XORI

        registers[fourLetterRD] = registers[fourLetterRS1] ^ immediatevalue;




    }
    if (instructionword.substr(0, instructionword.find(' ')) == "ori") { //ORI

        registers[threeLetterRD] = registers[threeLetterRS1] | immediatevalue;




    }
    if (instructionword.substr(0, instructionword.find(' ')) == "andi") { //ANDI

        registers[fourLetterRD] = registers[fourLetterRS1] & immediatevalue;



    }
    if (instructionword.substr(0, instructionword.find(' ')) == "slli") { //SLLI

        registers[fourLetterRD] = registers[fourLetterRS1] << immediatevalue;


    }
    if (instructionword.substr(0, instructionword.find(' ')) == "srli") { //SRLI

        registers[fourLetterRD] = (unsigned int)registers[fourLetterRS1] >> immediatevalue;

    }
    if (instructionword.substr(0, instructionword.find(' ')) == "srai") { //SRAI

        registers[fourLetterRD] = registers[fourLetterRS1] >> immediatevalue;

    }
    if (instructionword.substr(0, instructionword.find(' ')) == "lb") { //LB

        registers[twoLetterRD] = (memory[registers[twoLetterRS1] + immediatevalue] | (((memory[registers[twoLetterRS1] + immediatevalue] >> 7) ? 0xFFFFFF00 : 0x0)));

    }
    if (instructionword.substr(0, instructionword.find(' ')) == "lh") { //LH

        registers[twoLetterRD] = memory[registers[twoLetterRS1] + immediatevalue] | ((memory[registers[twoLetterRS1] + immediatevalue + 1]) << 8) | ((memory[registers[twoLetterRS1] + immediatevalue + 1] >> 7) ? 0xFFFF0000 : 0x0);

    }
    if (instructionword.substr(0, instructionword.find(' ')) == "lw") { //LW

        registers[twoLetterRD] = memory[registers[twoLetterRS1] + immediatevalue] | ((memory[registers[twoLetterRS1] + immediatevalue + 1]) << 8) | ((memory[registers[twoLetterRS1] + immediatevalue + 2]) << 16) | ((memory[registers[twoLetterRS1] + immediatevalue + 3]) << 24);
    }
    if (instructionword.substr(0, instructionword.find(' ')) == "lbu") { //LBU

        registers[threeLetterRD] = memory[registers[threeLetterRS1] + immediatevalue] | 0x0;
    }
    if (instructionword.substr(0, instructionword.find(' ')) == "lhu") { //LHU

        registers[threeLetterRD] = memory[registers[threeLetterRS1] + immediatevalue] | ((memory[registers[threeLetterRS1] + immediatevalue + 1]) << 8) | 0x0;
    }
    if (instructionword.substr(0, instructionword.find(' ')) == "beq") { //BEQ

        if (registers[threeLetterRS1] == registers[threeLetterRS2]) {

            pc = currentpc + immediatevalue;
        }

    }
    if (instructionword.substr(0, instructionword.find(' ')) == "bnq") { //BNQ

        if (registers[threeLetterRS1] != registers[threeLetterRS2]) {

            pc = currentpc + immediatevalue;
        }

    }
    if (instructionword.substr(0, instructionword.find(' ')) == "blt") { //BLT

        if (registers[threeLetterRS1] < registers[threeLetterRS2]) {

            pc = currentpc + immediatevalue;
        }

    }
    if (instructionword.substr(0, instructionword.find(' ')) == "bge") { //BGE

        if (registers[threeLetterRS1] >= registers[threeLetterRS2]) {

            pc = currentpc + immediatevalue;
        }

    }
    if (instructionword.substr(0, instructionword.find(' ')) == "bltu") { //BLTU

        if ((unsigned int)registers[threeLetterRS1] < (unsigned int)registers[threeLetterRS2]) {

            pc = currentpc + immediatevalue;
        }

    }
    if (instructionword.substr(0, instructionword.find(' ')) == "bgeu") { //BGEU

        if ((unsigned int)registers[threeLetterRS1] >= (unsigned int)registers[threeLetterRS2]) {

            pc = currentpc + immediatevalue;
        }

    }
    if (instructionword.substr(0, instructionword.find(' ')) == "sb") { //SB

        memory[registers[twoLetterRS1] + immediatevalue] = (registers[twoLetterRS2] & 0xFF);
    }
    if (instructionword.substr(0, instructionword.find(' ')) == "sh") { //SH

        memory[registers[twoLetterRS1] + immediatevalue] = (registers[twoLetterRS2] & 0xFF);
        memory[registers[twoLetterRS1] + immediatevalue + 1] = ((registers[twoLetterRS2] >> 8) & 0xFF);
    }
    if (instructionword.substr(0, instructionword.find(' ')) == "sw") { //SW

        memory[registers[twoLetterRS1] + immediatevalue] = (registers[twoLetterRS2] & 0xFF);
        memory[registers[twoLetterRS1] + immediatevalue + 1] = ((registers[twoLetterRS2] >> 8) & 0xFF);
        memory[registers[twoLetterRS1] + immediatevalue + 1] = ((registers[twoLetterRS2] >> 16) & 0xFF);
        memory[registers[twoLetterRS1] + immediatevalue + 1] = ((registers[twoLetterRS2] >> 24) & 0xFF);

    }
    if (instructionword.substr(0, instructionword.find(' ')) == "lui") { //LUI

        registers[threeLetterRD] = immediatevalue;
    }
    if (instructionword.substr(0, instructionword.find(' ')) == "auipc") { //AUIPC

        registers[fiveLetterRD] = pc + immediatevalue;
    }
    if (instructionword.substr(0, instructionword.find(' ')) == "jal") { //JAL

      //  registers[threeLetterRD] = pc;
        pc = currentpc + immediatevalue;

    }
    if (instructionword.substr(0, instructionword.find(' ')) == "jalr") { //JALR

      //  registers[threeLetterRD] = pc;
        pc = ((registers[threeLetterRS1] + immediatevalue) & 0xFFFFFFFE);

    }
    if (instructionword.substr(0, instructionword.find(' ')) == "mul") { //MUL

        registers[threeLetterRD] = registers[threeLetterRS1] * registers[threeLetterRS2];


    }
    if (instructionword.substr(0, instructionword.find(' ')) == "mulh") { //MULH

        registers[fourLetterRD] = (registers[fourLetterRS1] * registers[fourLetterRS2]) >> 32;


    }
    if (instructionword.substr(0, instructionword.find(' ')) == "mulhu") { //MULHU

        registers[fiveLetterRD] = ((unsigned int)registers[fiveLetterRS1] * (unsigned int)registers[fiveLetterRS2]) >> (unsigned int)32;


    }

    if (instructionword.substr(0, instructionword.find(' ')) == "div") { //DIV

        registers[threeLetterRD] = (registers[threeLetterRS1] / registers[threeLetterRS2]);

    }
    if (instructionword.substr(0, instructionword.find(' ')) == "divu") { //DIVU

        registers[fourLetterRD] = ((unsigned int)registers[fourLetterRS1] / (unsigned int)registers[fourLetterRS2]);

    }
    if (instructionword.substr(0, instructionword.find(' ')) == "rem") { //REM

        registers[threeLetterRD] = (registers[threeLetterRS1] % registers[threeLetterRS2]);

    }
    if (instructionword.substr(0, instructionword.find(' ')) == "remu") { //REMU

        registers[fourLetterRD] = ((unsigned int)registers[fourLetterRS1] % (unsigned int)registers[fourLetterRS2]);

    }
}

int main()
{

    int startingaddress; //INPUT OF STARTING ADDRESS FROM USER
    cout << "Enter Starting Address: " << endl;
    cin >> startingaddress;
    int pc = startingaddress; //PROGRAM COUNTER INTIALIZED WITH STARTING ADDRESS
    vector<int> memory;


    ifstream file("registervalues.txt"); //READING REGISTER INITIALIZATION
    int registers[32];
    for (int i = 0; i < 32; i++) {
        file >> registers[i];
    }
    // READING PROGRAM FILE ONE
    fstream instructionFile1;
    instructionFile1.open("instructionFile1.txt", ios::in);
    string instructionword;

    if (instructionFile1.is_open()) {

        while (getline(instructionFile1, instructionword)) {

            if (instructionword.substr(0, instructionword.find(' ')) == "ecall" | instructionword.substr(0, instructionword.find(' ')) == "ebreak" | instructionword.substr(0, instructionword.find(' ')) == "fence") {
                cout << "----Program terminated----" << endl;
                break;
            }
            simulator(instructionword, registers, pc, memory);

            pc = pc + 4;

            cout << "===================================" << endl;
            cout << "Current Instruction:" << endl;
            cout << instructionword << endl;
            cout << "Value Name:  Decimal    Binary   Hexa" << endl;
            cout << "-----------------------------" << endl;
            for (int i = 0; i < 32; i++) {
                cout << "Register x" << i << ":  " << registers[i] << "  ";
                decimalToBinary(registers[i]);
                cout << "  ";
                decimalToHex(registers[i]);
                cout << endl;
            }
            cout << "Program Counter: " << pc << "  ";
            decimalToBinary(pc);
            cout << "  ";
            decimalToHex(pc);
            cout << endl;


        }
    }

}


