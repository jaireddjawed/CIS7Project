#include <iostream>
#include <vector>
using namespace std;

/*
 * Example Graduate
 * Name: Jaired Jawed
 * Specialized Areas: Computer Science
 * Preferred Language: English
 * Preferred Language Fluency: .99
 */

struct Graduate {
    string name;
    string specializedArea;
    string preferredLanguage;
    double preferredLanguageFluency;
};

/*
 * Example Country
 * Name: United Kingdom
 * Required Specialized Area: Computer Science
 * Language: English
 */

struct Country {
    string name;
    string requiredSpecializedArea;
    string language;
};

vector<Graduate> availableGraduates;
vector<Country> availableCountries;

/* Function Headers */
void seedGraduates();
void seedCountries();
bool compareGraduateByLanguageFluency(Graduate, Graduate);
Country getSelectedCountry(string);

int main() {
    seedGraduates();
    seedCountries();

    int i = 0;

    cout << "Welcome to UCR's Doctors Without Borders Selection Program!" << endl;

    for (; i < availableCountries.size(); i++) {
        cout << i << ") " << availableCountries.at(i).name << endl;
    }

    string countryName;
    cout << "Please enter a country to get the recommended graduates: ";
    cin >> countryName;

    // get the selected country by its name
    Country selectedCountry = getSelectedCountry(countryName);
    vector<Graduate> selectedGraduates;
  
    for (i = 0; i < availableGraduates.size(); i++) {
        Graduate currentGrad = availableGraduates.at(i);
        // find all graduates that speak the selected country's language and required specialized area
        if (selectedCountry.language == currentGrad.preferredLanguage && selectedCountry.requiredSpecializedArea == currentGrad.specializedArea) {
            selectedGraduates.push_back(currentGrad);
        }
    }
    
    // Sorts the possible graduates for the selected countries by their fluency level
    sort(selectedGraduates.begin(), selectedGraduates.end(), compareGraduateByLanguageFluency);
    
    cout << "Here are the possible graduates for " << countryName << " by rank." << endl;

    // List the selected graduates info
    for (i = 0; i < selectedGraduates.size(); i++) {
        Graduate currentGrad = selectedGraduates.at(i);
        cout << "Name: " << currentGrad.name << endl;
        cout << "Specialized Area: " << currentGrad.specializedArea << endl;
        cout << "Preferred Language: " << currentGrad.preferredLanguage << endl;
        cout << "Lanuage Fluency: " << currentGrad.preferredLanguageFluency << endl;
        cout << endl;
    }
    
    cout << "End Program." << endl;

    return 0;
}

/* Push all graduates to vectors */
void seedGraduates() {
    Graduate grad1;
    grad1.name = "John Doe";
    grad1.preferredLanguage = "Tagalog";
    grad1.specializedArea = "Heart Surgery";
    grad1.preferredLanguageFluency = 0.71;
 
    availableGraduates.push_back(grad1);
 
    Graduate grad2;
    grad2.name = "Jane Doe";
    grad2.preferredLanguage = "Tagalog";
    grad2.specializedArea = "Heart Surgery";
    grad2.preferredLanguageFluency = 0.98;
 
    availableGraduates.push_back(grad2);
}

/* Push all countries to vectors */
void seedCountries() {
    Country country1;
    country1.name = "Phillipines";
    country1.language = "Tagalog";
    country1.requiredSpecializedArea = "Heart Surgery";
    
    availableCountries.push_back(country1);
}

/* Sorts Graduates by the greatest fluency level */
bool compareGraduateByLanguageFluency(const Graduate grad1, const Graduate grad2) {
    return grad1.preferredLanguageFluency > grad2.preferredLanguageFluency;
}

/* Find the Country by its name */
Country getSelectedCountry(string countryName) {
    int i = 0;
    for (; i < availableCountries.size(); i++) {
        if (countryName == availableCountries.at(i).name) {
            return availableCountries.at(i);
        }
    }
    return availableCountries.at(0);
}
