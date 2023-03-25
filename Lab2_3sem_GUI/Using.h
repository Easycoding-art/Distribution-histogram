#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Binary_tree.h"
#include "Person.h"
#include "IDictionary.h"

bool partiton_comp(Person person, int point, int r) {
    if (person.Age >= point - r && person.Age <= point + r) {
        return true;
    }
    else {
        return false;
    }
}

