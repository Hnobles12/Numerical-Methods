#ifndef MISC_HPP
#define MISC_HPP
bool sign(double num){
    if (num >= 0){return true;}
    else {return false;}
    
}

int abs(int num){
    if (num < 0){
        return num*-1;
    }
    return num;
}

double abs(double num){
    if (num < 0){
        return num*-1;
    }
    return num;
}

#endif