#include <iostream>

struct comp {
    double rill;
    double imaj;
};

comp addition(comp num_1, comp num_2);
comp substraction(comp num_1, comp num_2);
comp multiplication(comp num_1, comp num_2);
comp division(comp num_1, comp num_2);

int main() {
    comp num_1, num_2, tempComp;
    char option;
    char isContinue = 'y';
    enum {ADD = '+', SUBS = '-', MULTI = '*', DIV = '/', END};

    while (isContinue == 'y' || isContinue == 'Y') {
        std::cout << "Input first real number: ";
        std::cin >> num_1.rill;
        std::cout << "Input first image number: ";
        std::cin >> num_1.imaj;
        std::cout << "Choose your operator '+', '-', '*', '/': ";
        std::cin >> option;
        std::cout << "Input second real number: ";
        std::cin >> num_2.rill;
        std::cout << "Input second image number: ";
        std::cin >> num_2.imaj;

        switch (option)
        {
        case ADD:
            tempComp = addition(num_1, num_2);
            std::cout << "result of addition: " << tempComp.rill << " + " << tempComp.imaj << "i" << std::endl;
            break;
        
        case SUBS:
            tempComp = substraction(num_1, num_2);
            std::cout << "result of substraction: " << tempComp.rill << " - " << tempComp.imaj << "i" << std::endl;
            break;

        case MULTI:
            tempComp = multiplication(num_1, num_2);
            std::cout << "result of multiplication: " << tempComp.rill << " * " << tempComp.imaj << "i" << std::endl;
            break;

        case DIV:
            if(num_2.rill != 0 && num_2.imaj != 0){
                tempComp = division(num_1, num_2);
                std::cout << "result of division: " << tempComp.rill << " / " << tempComp.imaj << "i" << std::endl;
            } else {
                std::cout << "Cannot divide by zero" << std::endl;
            }
            break;
            
        default:
            std::cout << "Your input doesnt match" << std::endl;
            break;
        }

        std::cout << "Do you want to continue? (y/n): ";
        std::cin >> isContinue;
    }

    return 0;
}

comp addition(comp num_1, comp num_2){
    comp tempComp;

    tempComp.rill = num_1.rill + num_2.rill;
    tempComp.imaj = num_1.imaj + num_2.imaj;

    return tempComp;
}

comp substraction(comp num_1, comp num_2){
    comp tempComp;

    tempComp.rill = num_1.rill - num_2.rill;
    tempComp.imaj = num_1.imaj - num_2.imaj;

    return tempComp;
}

comp multiplication(comp num_1, comp num_2){
    comp tempComp;

    tempComp.rill = (num_1.rill * num_2.rill) - (num_1.imaj * num_2.imaj);
    tempComp.imaj = (num_1.rill * num_2.imaj) + (num_1.imaj * num_2.rill);

    return tempComp;
}

comp division(comp num_1, comp num_2){
    comp tempComp;
    
    double downDiv = (num_2.rill * num_2.rill) + (num_2.imaj * num_2.imaj);
    tempComp.rill = ((num_1.rill * num_2.rill) + (num_1.imaj * num_2.imaj))/downDiv;
    tempComp.imaj = ((num_1.imaj * num_2.rill) - (num_1.rill * num_2.imaj))/downDiv;
    return tempComp;
}
