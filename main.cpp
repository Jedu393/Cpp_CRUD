#include <fstream>
#include <iostream>
#include <ios>
#include <iomanip>
#include <limits>
#include <string>

struct variables {

    //

    std::string errorMsg;

    int numberOfStudentsToEncode;
    int numberOfGradesToEncode;

    int &rows = numberOfStudentsToEncode; //REVIEW: as 2D array rows
    int &cols = numberOfGradesToEncode; //REVIEW: as 2D array columns

    std::string userAverageMsg;

};

struct tags {

    std::string open_curlybrack;  // REVIEW: opening/left curly bracket - {
    std::string close_curlybrack; // REVIEW: closing/right curly bracket - }    
    std::string style_tags;       // REVIEW: style html tags (i.e - table, td, th, etc ...)
    std::string start;            // REVIEW: starting of html - <!DOCTYPE html>

    std::string start_html;       // REVIEW: starting of html tags - <html>
    std::string start_head;       // REVIEW: starting of head - <head>
    std::string start_body;       // REVIEW: starting of body - <body>
    std::string start_heading1;   // REVIEW: starting of heading1 - <h1>
    std::string start_style;      // REVIEW: starting of style - <style>
    std::string start_table;      // REVIEW: starting of table - <table>
    std::string start_table_h;    // REVIEW: starting of table header - <th>
    std::string start_table_r;    // REVIEW: starting of table row - <tr>
    std::string start_table_d;    // REVIEW: starting of table data - <td>      

    std::string close_html;       // REVIEW: closing of html tags - </html>
    std::string close_head;       // REVIEW: closing of head - </head>
    std::string close_body;       // REVIEW: closing of body - </body>
    std::string close_heading1;   // REVIEW: closing of heading1 - </h1>
    std::string close_style;      // REVIEW: closing of style - </style>
    std::string close_table;      // REVIEW: closing of table - </table>
    std::string close_table_h;    // REVIEW: closing of table header - </th>
    std::string close_table_r;    // REVIEW: closing of table row - </tr>
    std::string close_table_d;    // REVIEW: closing of table data - </td>      

};

auto EnterValidFileExtnFormat(std::string &enterName) -> std::string {

    //FIXME: first occurrence of ., h, t, m, and l in a string input - early return the string val

    std::cin >> enterName;

    const std::string fileDotHtml = ".html"; //TODO:
    
    const size_t fileDotHtmlFound = enterName.find_last_of(fileDotHtml);

    const bool isDotHtml          = fileDotHtmlFound != std::string::npos;

    if(isDotHtml) {
        std::cout << "\n\"" << enterName << "\" successfully created.\n";
    }

    if(!isDotHtml) {
        std::cout << "\nInvalid Format -> \"" << enterName << "\" file failed to create.";
        std::cout << "\nFile must end with dot html(.html) file extension";
        std::cout << "\nRe-enter the name of the file and end it with dot html(.html) file extension: ";

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<::std::streamsize>::max(), '\n');

        return EnterValidFileExtnFormat(enterName);
    }

    return enterName;

}

template<typename ArrayType>
ArrayType **new_2d_array(const int &rows, const int &columns) { //NOTE: allocate 2d array

    //NOTE: nothing to change here

    ArrayType **p_2d_array = nullptr;

    p_2d_array = new ArrayType*[rows];

    for(auto i = 0; i < rows; i ++) {
        p_2d_array[i] = new ArrayType[columns];
    }

    return p_2d_array;

}

template<typename ArrayType>
auto delete_2d_array(ArrayType **p_2d_array) -> void { //NOTE: deallocate 2D array

    //NOTE: nothing to change here

    delete[] *p_2d_array;
    *p_2d_array = nullptr; 

    delete[] p_2d_array;
    p_2d_array = nullptr;

}

template<typename T>
auto EnterValidVar(T &var, const std::string &errorMsg) -> T {

    while(true) { //REVIEW: infinite loop
        std::cin >> var;

        if(!std::cin) { //REVIEW: never stop the loop if this condition is met
            std::cout << errorMsg;

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<::std::streamsize>::max(), '\n');
            
            continue;
        }
        else //REVIEW: else, if the condition is false - break the infinite loop
            break;
    }

    return var;

}

auto InputStudentNumberCodeInFile(std::fstream &fileHtml, size_t &enterNumberCode) -> size_t {

}

auto EnterValidStudentNumberCode(std::fstream &fileHtml, size_t &enterNumberCode) -> size_t {

    variables *warn1 = new variables();
    variables *warn2 = new variables();

    warn1->errorMsg = "\nInvalid Format/Not a valid Student Number Code\nRe-enter Student Number Code: ";
    warn2->errorMsg = "\nInvalid Format/Student Number Code must be 10 maximum digits only\nRe-enter Student Number Code: ";

    size_t studentNumberCode = 0;
    int countNumberCode      = 0;

    bool isNotAnInteger      = false;
    bool isNot10Digits       = false;

    std::cin >> enterNumberCode;

    studentNumberCode = enterNumberCode;

    if(studentNumberCode < 0) {
        studentNumberCode = -1 * studentNumberCode;
    }

    while(studentNumberCode > 0) {
        studentNumberCode /= 10;
        countNumberCode++;
    }

    if(!std::cin) {
        isNotAnInteger = true;

        std::cout << warn1->errorMsg;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return EnterValidStudentNumberCode(fileHtml, enterNumberCode);
    }

    if(countNumberCode != 10) {
        isNot10Digits = true;

        std::cout << warn2->errorMsg;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return EnterValidStudentNumberCode(fileHtml, enterNumberCode);
    }

    //FIXME: 
    // if(isNotAnInteger == false && isNot10Digits == false) {
    //     fileHtml << enterNumberCode;
    // }

    delete warn1;
    warn1 = nullptr;

    delete warn2;
    warn2 = nullptr;

    return enterNumberCode;

}

auto EnterValidGradePerSubject(std::fstream &fileHtml, double &enterGradeSubjNo) -> double {

    variables *warn1 = new variables();
    variables *warn2 = new variables();

    warn1->errorMsg = "\nInvalid Format/Not an integer\nRe-enter Grade for Subject no. ";
    warn2->errorMsg = "\nInvalid Format/Grade(s) per Subject should be between 1 to 100 only\nRe-enter Grade for Subject no. ";
    
    bool isNotDecimalNumber = false;
    bool isNotValidDecimalN = false;

    std::cin >> enterGradeSubjNo;

    if(!std::cin) {
        isNotDecimalNumber = true;

        std::cout << warn1->errorMsg;
        
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return EnterValidGradePerSubject(fileHtml, enterGradeSubjNo);
    }

    if(enterGradeSubjNo <= 0 || enterGradeSubjNo >= 101) {
        isNotValidDecimalN = true;

        std::cout << warn2->errorMsg;
        
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return EnterValidGradePerSubject(fileHtml, enterGradeSubjNo);
    }

    //FIXME: 
    // if(isNotDecimalNumber == false && isNotValidDecimalN == false) {
    //     fileHtml << enterGradeSubjNo;
    // }

    delete warn1;
    warn1 = nullptr;

    delete warn2;
    warn2 = nullptr;

    return enterGradeSubjNo;

}

auto CreateHtmlTableRowCol(std::fstream &fileHtml, const int &rows, const int &columns) -> void {

    tags *resizable_table = new tags();

    resizable_table->start_table   = "\n<table>";
    resizable_table->start_table_r = "\n\t<tr>";
    resizable_table->start_table_h = "\n\t\t<th>";
    resizable_table->start_table_d = "\n\t\t<td>";

    resizable_table->close_table   = "\n</table>";
    resizable_table->close_table_r = "\n\t</tr>";
    resizable_table->close_table_h = "</th>";
    resizable_table->close_table_d = "</td>";

    fileHtml << resizable_table->start_table;

    for(auto i = 0; i < rows; i++) { //ANCHOR: Table Header

        fileHtml << resizable_table->start_table_r;

        for(auto j = 0; j < columns; i++) {
            fileHtml << resizable_table->start_table_h << "Student Number Code" << resizable_table->close_table_h;
            break;
        }

        for(auto k = 1; k < columns + 1; k++) {
            fileHtml << resizable_table->start_table_h << "Subject Grade No. " << k << resizable_table->close_table_h;
        }

        for(auto l = 1; l < columns + 1; l++) {
            fileHtml << resizable_table->start_table_h << "Average Grade" << resizable_table->close_table_h;
            break;
        }

        for(auto m = 1; m < columns + 1; m++) {
            fileHtml << resizable_table->start_table_h << "Result" << resizable_table->close_table_h;
            break;
        }

        fileHtml << resizable_table->close_table_r;

        break;

    }

    

    fileHtml << resizable_table->close_table;

    delete resizable_table;
    resizable_table = nullptr;

}

auto CreateHtmlTable(std::fstream &fileHtml, const int &rows, const int &columns) -> void {

    tags *table        = new tags();
    tags *css_table    = new tags();
    tags *css_font     = new tags();
    tags *css_border1  = new tags();
    tags *css_width    = new tags();
    tags *css_td_th    = new tags();
    tags *css_border2  = new tags();
    tags *css_txt_algn = new tags();
    tags *css_padding  = new tags();
    tags *css_tr       = new tags();
    tags *css_bg_color = new tags();

    table->start             = "<!DOCTYPE html>";
    table->start_html        = "\n<html>";
    table->start_head        = "\n<head>";
    table->start_style       = "\n<style>";

    table->open_curlybrack   = " {";
    table->close_curlybrack  = "\n}";

    css_table->style_tags    = "\ntable";
    css_font->style_tags     = "\n\tfont-family: arial, sans-serif;";
    css_border1->style_tags  = "\n\tborder-collapse: collapse;";
    css_width->style_tags    = "\n\twidth: 100%";

    css_td_th->style_tags    = "\ntd, th";
    css_border2->style_tags  = "\n\tborder: 1px solid #dddddd;";
    css_txt_algn->style_tags = "\n\ttext-align: left;";
    css_padding->style_tags  = "\n\tpadding: 5px;";

    css_tr->style_tags       = "\ntr:nth-child(even)";
    css_bg_color->style_tags = "\n\tbackground-color: #dddddd;";

    table->close_style       = "\n</style>";
    table->close_head        = "\n</head>";

    table->start_body        = "\n<body>";
    table->close_body        = "\n</body>";

    table->close_html        = "\n</html>";

    //NOTE: make html tag
    fileHtml << table->start;
    fileHtml << table->start_html;

    fileHtml << "\n"; //NOTE: new line for pretty formatting
    fileHtml << table->start_head;
    fileHtml << table->start_style;

    fileHtml << css_table->style_tags << table->open_curlybrack;
    fileHtml << css_font->style_tags;
    fileHtml << css_border1->style_tags;
    fileHtml << css_width->style_tags;
    fileHtml << table->close_curlybrack;

    fileHtml << css_td_th->style_tags << table->open_curlybrack;
    fileHtml << css_border2->style_tags;
    fileHtml << css_txt_algn->style_tags;
    fileHtml << css_padding->style_tags;
    fileHtml << table->close_curlybrack;

    fileHtml << css_tr->style_tags << table->open_curlybrack;
    fileHtml << css_bg_color->style_tags;
    fileHtml << table->close_curlybrack;

    fileHtml << table->close_style;
    fileHtml << table->close_head;

    fileHtml << "\n"; //NOTE: new line for pretty formatting
    fileHtml << table->start_body;
    CreateHtmlTableRowCol(fileHtml, rows, columns);
    fileHtml << table->close_body;

    fileHtml << "\n"; //NOTE: new line for pretty formatting
    fileHtml << table->close_html;
    //NOTE: end of making html tag

    //NOTE: delete and free the allocated memory
    delete table;
    table = nullptr;

    delete css_table;
    css_table = nullptr;

    delete css_font;
    css_font = nullptr;

    delete css_border1;
    css_border1 = nullptr;

    delete css_width;
    css_width = nullptr;

    delete css_td_th;
    css_td_th = nullptr;

    delete css_border2;
    css_border2 = nullptr;

    delete css_txt_algn;
    css_txt_algn = nullptr;

    delete css_padding;
    css_padding = nullptr;

    delete css_tr;
    css_tr = nullptr;

    delete css_bg_color;
    css_bg_color = nullptr;

}

auto WriteIntoFile(std::fstream &fileHtml) -> void {

    variables *warn1 = new variables();
    variables *warn2 = new variables();
    variables *val   = new variables();

    warn1->errorMsg = "\nInvalid Format/Not a valid Number of Student(s)\nRe-enter how many Number of Student(s) to Encode: ";
    warn2->errorMsg = "\nInvalid Format/Not a valid Number of Grade(s)\nRe-enter how many Number of Grade(s) to Encode  : ";

    size_t enterNumberCode  = 0;
    double enterGradeSubjNo = 0;

    double sumAllGrades     = 0;
    double generalAverage   = 0;

    std::cout << "\nEnter how many Number of Student(s) to Encode   : ";
    EnterValidVar(val->numberOfStudentsToEncode, warn1->errorMsg);

    std::cout << "\nEnter how many Number of Grade(s) to Encode     : ";
    EnterValidVar(val->numberOfGradesToEncode, warn2->errorMsg);

    //ANCHOR: start
    double **listStudentGradesAverage = new_2d_array<double>(val->rows, val->cols);

    std::cout << "\nEncode Student Grades\n";
    for(auto i = 0; i < val->rows; i++) {

        for(auto j = 0; j < val->cols + 1; j++) {
            std::cout << "\nStudent No. " << i + 1 << ". Enter Student Number Code   : ";
            EnterValidStudentNumberCode(fileHtml, enterNumberCode);

            std::cout << "\nEncode " << std::fixed << std::setprecision(0) << enterNumberCode << "\'s Grades:";
            break;
        }

        for(auto k = 1; k < val->cols + 1; k++) {
            std::cout << "\nEnter Grade on Subject No. " << k << ".   : ";
            EnterValidGradePerSubject(fileHtml, enterGradeSubjNo);
        }

    }

    // for(auto i = 0; i < val->rows; i++) {

    //     for(auto j = 0; j < (val->rows + 1); j++) {



    //     }

    // }

    CreateHtmlTable(fileHtml, val->rows, val->cols);

    //NOTE: delete and free the allocated memory
    delete warn1;
    warn1 = nullptr;

    delete warn2;
    warn2 = nullptr;

    delete val;
    val = nullptr;

    delete_2d_array<double>(listStudentGradesAverage);

}

auto CreateUserFile(const std::string &userFileName) -> void {

    std::fstream fileHtml(userFileName, std::ios::app);

    if(fileHtml.is_open()) {
        std::cout << "\n\"" << userFileName << "\" is now open\n";
    }

    WriteIntoFile(fileHtml);

    fileHtml.close();

}

auto EnterFileName() -> void {

    std::string enterName = "";

    std::cout << "\nEnter the name of the file and end it with dot html(.html) file extension   : ";
    EnterValidFileExtnFormat(enterName);

    const std::string userFileName = enterName;

    CreateUserFile(userFileName);

}

auto main() -> int {

    EnterFileName();

}