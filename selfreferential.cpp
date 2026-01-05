#include <string>
#include <iostream>
using namespace std;

string tape = "";
string quote= "";
void selfQueue(string w){
    tape += "selfQueue(R\"(" + w + ")\");\n";
    quote = w;
}

void machineA(){
    selfQueue(R"(
void machineB(){
    string tapeA = tape;
    tape = "";

    tape += "#include <string>\n";
    tape += "#include <iostream>\n";
    tape += "using namespace std;\n\n";

    tape += "string tape = \"\";\n";
    tape += "string quote= \"\";\n";
    tape += "void selfQueue(string w){\n";
    tape += "    tape += \"selfQueue(R\\\"(\" + w + \")\\\");\\n\";\n";
    tape += "    quote = w;\n";
    tape += "}\n\n";
    tape += "void machineA(){\n    ";
    tape += tapeA;
    tape += "}\n";
    tape += quote;

    tape += "\n";
    tape += "int main() {\n";
    tape += "    machineA();\n";
    tape += "    machineB();\n";
    tape += "}\n";

    cout << tape;
}
)");
}

void machineB(){
    string tapeA = tape;
    tape = "";

    tape += "#include <string>\n";
    tape += "#include <iostream>\n";
    tape += "using namespace std;\n\n";

    tape += "string tape = \"\";\n";
    tape += "string quote= \"\";\n";
    tape += "void selfQueue(string w){\n";
    tape += "    tape += \"selfQueue(R\\\"(\" + w + \")\\\");\\n\";\n";
    tape += "    quote = w;\n";
    tape += "}\n\n";
    tape += "void machineA(){\n    ";
    tape += tapeA;
    tape += "}\n";
    tape += quote;

    tape += "\n";
    tape += "int main() {\n";
    tape += "    machineA();\n";
    tape += "    machineB();\n";
    tape += "}\n";

    cout << tape;
}

int main() {
    machineA();
    machineB();
}