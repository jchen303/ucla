#include "MyString.hpp"
#include <iostream>
#include <string>
using namespace std;

int main() {

//    MyString s = "Hello World";
//    cout << s << endl;
//    s += '!';
//    cout << s << endl;
//    s += "!!";
//    cout << s << endl;
//
//    // These compile but don't do anything useful yet.
//    // They simply return static_cast<size_t>(-1).
//    cout << s.find("llo ") << endl;
//    cout << s.rfind('o', 10) << endl;
//    cout << s.find('o', 15) << endl;
//
//    cout << s.substr(8, 3) << endl;
//    MyString test = "jeremy";
//    cout << test.size() << endl;
//    test.resize(8);
//    cout << test.size() << endl;
//    cout << test << endl;
//    test.resize(4);
//    cout << test.size() << endl;
//    cout << test << endl;
//    test.resize(7, 'c');
//    cout << test.size() << endl;
//    cout << test << endl;
    
//    cout << "I've made it so that you can cin too." << endl;
//    MyString s1;
//    MyString s2;
//    cin  >> s1 >> s2;
//    cout << s1 + " " + s2 << endl;

    const string   emptyString;
    const MyString emptyMyString;

    const string   auxString   = "0123456789";
    const MyString auxMyString = "0123456789";

    const string   testString   = auxString   + auxString   + auxString   + auxString;
    const MyString testMyString = auxMyString + auxMyString + auxMyString + auxMyString;
    
//    cout << testString.at(39) << endl;
//    cout << testString.find("", 30) << endl;
//    cout << testString.find("", 40) << endl;
//    cout << testMyString.find("", 40) << endl;
//    cout << testString.find("", 60) << endl;

    cout << "emptyString   is " << emptyString   << endl;
    cout << "emptyMyString is " << emptyMyString << endl;
    cout << "testString    is " << testString    << endl;
    cout << "testMyString  is " << testMyString  << endl << endl;

    cout << "First, we test substr:"                                      << endl;
    cout << "There should be two blank lines and then repetitions..."     << endl;
    cout << testString.substr(40   ) << " " << testMyString.substr(40   ) << endl;
    cout << testString.substr(40,10) << " " << testMyString.substr(40,10) << endl;
    cout << testString.substr(20   ) << " " << testMyString.substr(20   ) << endl;
    cout << testString.substr(20,30) << " " << testMyString.substr(20,30) << endl;
    cout << testString.substr(20,10) << " " << testMyString.substr(20,10) << endl << endl;

    cout << "Next, we test find and rfind for chars and strings:" << endl << endl;
    cout << "Every 8 lines there's a break;"                      << endl;
    cout << "other than that, each line should say \"true\"..."   << endl << endl;

    cout << boolalpha;

    cout << ( testString.find('a'   ) ==  testMyString.find('a'   )) << endl;
    cout << ( testString.find('a',20) ==  testMyString.find('a',20)) << endl;
    cout << ( testString.find('a',40) ==  testMyString.find('a',40)) << endl;
    cout << ( testString.find('a',60) ==  testMyString.find('a',60)) << endl;
    cout << (testString.rfind('a'   ) == testMyString.rfind('a'   )) << endl;
    cout << (testString.rfind('a',20) == testMyString.rfind('a',20)) << endl;
    cout << (testString.rfind('a',40) == testMyString.rfind('a',40)) << endl;
    cout << (testString.rfind('a',60) == testMyString.rfind('a',60)) << endl << endl;

    cout << ( testString.find('0'   ) ==  testMyString.find('0'   )) << endl;
    cout << ( testString.find('0',20) ==  testMyString.find('0',20)) << endl;
    cout << ( testString.find('0',40) ==  testMyString.find('0',40)) << endl;
    cout << ( testString.find('0',60) ==  testMyString.find('0',60)) << endl;
    cout << (testString.rfind('0'   ) == testMyString.rfind('0'   )) << endl;
    cout << (testString.rfind('0',20) == testMyString.rfind('0',20)) << endl;
    cout << (testString.rfind('0',40) == testMyString.rfind('0',40)) << endl;
    cout << (testString.rfind('0',60) == testMyString.rfind('0',60)) << endl << endl;

    cout << ( testString.find('8'   ) ==  testMyString.find('8'   )) << endl;
    cout << ( testString.find('8',20) ==  testMyString.find('8',20)) << endl;
    cout << ( testString.find('8',40) ==  testMyString.find('8',40)) << endl;
    cout << ( testString.find('8',60) ==  testMyString.find('8',60)) << endl;
    cout << (testString.rfind('8'   ) == testMyString.rfind('8'   )) << endl;
    cout << (testString.rfind('8',20) == testMyString.rfind('8',20)) << endl;
    cout << (testString.rfind('8',40) == testMyString.rfind('8',40)) << endl;
    cout << (testString.rfind('8',60) == testMyString.rfind('8',60)) << endl << endl;

    cout << ( testString.find('9'   ) ==  testMyString.find('9'   )) << endl;
    cout << ( testString.find('9',20) ==  testMyString.find('9',20)) << endl;
    cout << ( testString.find('9',40) ==  testMyString.find('9',40)) << endl;
    cout << ( testString.find('9',60) ==  testMyString.find('9',60)) << endl;
    cout << (testString.rfind('9'   ) == testMyString.rfind('9'   )) << endl;
    cout << (testString.rfind('9',20) == testMyString.rfind('9',20)) << endl;
    cout << (testString.rfind('9',40) == testMyString.rfind('9',40)) << endl;
    cout << (testString.rfind('9',60) == testMyString.rfind('9',60)) << endl << endl;

    cout << ( testString.find(""   ) ==  testMyString.find(""   )) << endl;
    cout << ( testString.find("",20) ==  testMyString.find("",20)) << endl;
    cout << ( testString.find("",40) ==  testMyString.find("",40)) << endl;
    cout << ( testString.find("",60) ==  testMyString.find("",60)) << endl;
    cout << (testString.rfind(""   ) == testMyString.rfind(""   )) << endl;
    cout << (testString.rfind("",20) == testMyString.rfind("",20)) << endl;
    cout << (testString.rfind("",40) == testMyString.rfind("",40)) << endl;
    cout << (testString.rfind("",60) == testMyString.rfind("",60)) << endl << endl;

    cout << ( testString.find("018"   ) ==  testMyString.find("018"   )) << endl;
    cout << ( testString.find("018",20) ==  testMyString.find("018",20)) << endl;
    cout << ( testString.find("018",40) ==  testMyString.find("018",40)) << endl;
    cout << ( testString.find("018",60) ==  testMyString.find("018",60)) << endl;
    cout << (testString.rfind("018"   ) == testMyString.rfind("018"   )) << endl;
    cout << (testString.rfind("018",20) == testMyString.rfind("018",20)) << endl;
    cout << (testString.rfind("018",40) == testMyString.rfind("018",40)) << endl;
    cout << (testString.rfind("018",60) == testMyString.rfind("018",60)) << endl << endl;

    cout << ( testString.find("648"   ) ==  testMyString.find("648"   )) << endl;
    cout << ( testString.find("648",20) ==  testMyString.find("648",20)) << endl;
    cout << ( testString.find("648",40) ==  testMyString.find("648",40)) << endl;
    cout << ( testString.find("648",60) ==  testMyString.find("648",60)) << endl;
    cout << (testString.rfind("648"   ) == testMyString.rfind("648"   )) << endl;
    cout << (testString.rfind("648",20) == testMyString.rfind("648",20)) << endl;
    cout << (testString.rfind("648",40) == testMyString.rfind("648",40)) << endl;
    cout << (testString.rfind("648",60) == testMyString.rfind("648",60)) << endl << endl;

    cout << ( testString.find("012"   ) ==  testMyString.find("012"   )) << endl;
    cout << ( testString.find("012",20) ==  testMyString.find("012",20)) << endl;
    cout << ( testString.find("012",40) ==  testMyString.find("012",40)) << endl;
    cout << ( testString.find("012",60) ==  testMyString.find("012",60)) << endl;
    cout << (testString.rfind("012"   ) == testMyString.rfind("012"   )) << endl;
    cout << (testString.rfind("012", 9) == testMyString.rfind("012", 9)) << endl;
    cout << (testString.rfind("012",40) == testMyString.rfind("012",40)) << endl;
    cout << (testString.rfind("012",60) == testMyString.rfind("012",60)) << endl << endl;

    cout << ( testString.find("890"   ) ==  testMyString.find("890"   )) << endl;
    cout << ( testString.find("890",20) ==  testMyString.find("890",20)) << endl;
    cout << ( testString.find("890",40) ==  testMyString.find("890",40)) << endl;
    cout << ( testString.find("890",60) ==  testMyString.find("890",60)) << endl;
    cout << (testString.rfind("890"   ) == testMyString.rfind("890"   )) << endl;
    cout << (testString.rfind("890",20) == testMyString.rfind("890",20)) << endl;
    cout << (testString.rfind("890",40) == testMyString.rfind("890",40)) << endl;
    cout << (testString.rfind("890",60) == testMyString.rfind("890",60)) << endl << endl;

    cout << ( testString.find("789"   ) ==  testMyString.find("789"   )) << endl;
    cout << ( testString.find("789",30) ==  testMyString.find("789",30)) << endl;
    cout << ( testString.find("789",40) ==  testMyString.find("789",40)) << endl;
    cout << ( testString.find("789",60) ==  testMyString.find("789",60)) << endl;
    cout << (testString.rfind("789"   ) == testMyString.rfind("789"   )) << endl;
    cout << (testString.rfind("789",20) == testMyString.rfind("789",20)) << endl;
    cout << (testString.rfind("789",40) == testMyString.rfind("789",40)) << endl;
    cout << (testString.rfind("789",60) == testMyString.rfind("789",60)) << endl << endl;

    cout << "Every 6 lines there's a break;"                    << endl;
    cout << "other than that, each line should say \"true\"..." << endl << endl;

    cout << ( emptyString.find('0'   ) ==  emptyMyString.find('0'   )) << endl;
    cout << ( emptyString.find('0', 0) ==  emptyMyString.find('0', 0)) << endl;
    cout << ( emptyString.find('0',20) ==  emptyMyString.find('0',20)) << endl;
    cout << (emptyString.rfind('0'   ) == emptyMyString.rfind('0'   )) << endl;
    cout << (emptyString.rfind('0', 0) == emptyMyString.rfind('0', 0)) << endl;
    cout << (emptyString.rfind('0',20) == emptyMyString.rfind('0',20)) << endl << endl;

    cout << ( emptyString.find("0"   ) ==  emptyMyString.find("0"   )) << endl;
    cout << ( emptyString.find("0", 0) ==  emptyMyString.find("0", 0)) << endl;
    cout << ( emptyString.find("0",20) ==  emptyMyString.find("0",20)) << endl;
    cout << (emptyString.rfind("0"   ) == emptyMyString.rfind("0"   )) << endl;
    cout << (emptyString.rfind("0", 0) == emptyMyString.rfind("0", 0)) << endl;
    cout << (emptyString.rfind("0",20) == emptyMyString.rfind("0",20)) << endl << endl;

    cout << ( emptyString.find(""   ) ==  emptyMyString.find(""   )) << endl;
    cout << ( emptyString.find("", 0) ==  emptyMyString.find("", 0)) << endl;
    cout << ( emptyString.find("",20) ==  emptyMyString.find("",20)) << endl;
    cout << (emptyString.rfind(""   ) == emptyMyString.rfind(""   )) << endl;
    cout << (emptyString.rfind("", 0) == emptyMyString.rfind("", 0)) << endl;
    cout << (emptyString.rfind("",20) == emptyMyString.rfind("",20)) << endl << endl;

    const string   testString2   = "0000";
    const MyString testMyString2 = "0000";

    cout << "The final two lines should say \"true\"..." << endl << endl;

    cout << ( testString2.find("0001") ==  testMyString2.find("0001")) << endl;
    cout << (testString2.find("00001") == testMyString2.find("00001")) << endl << endl;
    
    return 0;
}
