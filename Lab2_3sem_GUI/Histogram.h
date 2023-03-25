#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Binary_tree.h"
#include "Person.h"
#include "IDictionary.h"
#include "Using.h"
class Histogram
{
public:
    Histogram(Sequence<Person> people_sequence, int a, int b, int distr_number, int r) {
        dictionary = person_filter(people_sequence, partiton_comp, a, b, r);
        A = a;
        B = b;
        Distr_number = distr_number;
        R = r;
    };
    void draw() {
        Sequence<int> seq = dictionary.Keys();
        Sequence<Person> seq_people = Sequence<Person>();
        ofstream f("Lab2_histogram.txt");
        f << this->Distr_number << "\n";
        int key;
        for (int i = 0; i < seq.size(); i++)
        {
            key = seq.peek(i);
            if (dictionary.ContainsKey(key) == true) {
                seq_people = dictionary.Get(key);
                f << seq_people.size() << "\n";
            }
        }
        f.close();
        std::string cmd = "python Histogram.py ";
        system(cmd.c_str());
    }

private:
    Sequence<Person> get_distr(Sequence<Person> seq, bool (*distr)(Person, int, int), int point, int r) {
        Sequence<Person> res = Sequence<Person>();
        for (int i = 0; i < seq.size(); i++) {
            if (distr(seq.peek(i), point, r) == true) {
                res = res.add(seq.peek(i));
            }
        }
        return res;
    }
    IDictionary<int, Sequence<Person>> person_filter(Sequence<Person> people, bool (*distr)(Person, int, int), int a, int b, int r) {//distr - само разбиение
        Sequence<Person> seq = Sequence<Person>();
        IDictionary<int, Sequence<Person>> dict = IDictionary<int, Sequence<Person>>(a, seq);
        for (int i = a; i < b; i += r)
        {
            seq = get_distr(people, distr, i, r);
            dict.Add(i, seq);
        }
        return dict;
    }

    IDictionary<int, Sequence<Person>> dictionary;
    int A;
    int B;
    int Distr_number;
    int R;
};
