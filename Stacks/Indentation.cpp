#include<bits/stdc++.h>
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	//string str = "public class PrettyPrint { public static void main(String args[]) { System.out.println(\"Hello World\"); String input = \"This is a sample code\"; System.out.println(Indent(input)); } public static String Indent(String input) { return \"Indented: \" + input; } }";
	string str = "public class PrettyPrint { public static void main(String args[]) {          System.out.println(\"Hello ;;;; {{{{ ;;;; ;;; {{{{{{{{{{World\"); {} {  } String input = \"This is a sample code\"; System.out.println(Indent(input));           } public static String Indent(String input) { return \"Indented: \" + input; } }";
	int spaces = 0;

	string Indented_string = "";
	int n = str.size();
	for(int i=0;i<n;i++){

		if(str[i] == '"'){
			Indented_string += str[i];
			i++;
			while(str[i] != '"' ){
				Indented_string += str[i];
				i++;
			}

			Indented_string += str[i];
			continue;
		}


		if(str[i] == '{'){
			Indented_string += str[i];
			spaces += 4;
		/*	int k = i+1;
			while(str[k] == ' '){
				k++;
			}
			
			if(str[k] != '}'){
				i = k - 1;
				continue;
			}*/
			Indented_string += "\n";

			for(int j=0;j<spaces;j++){
				Indented_string += " ";
			}
			int j = i+1;
			while(str[j] == ' '){
				j++;
			}
			i = j -1;

		}else if(str[i] == '}'){
			spaces = spaces - 4;
			Indented_string += "\n";
			for(int j=0;j<spaces;j++){
				Indented_string += " ";
			}
			Indented_string += str[i];
			
			int j = i + 1;
			while(str[j] == ' '){
				j++;
			}
			if(str[j] == '}'){
				continue;
			}
			Indented_string += "\n";

			for(int j=0;j<spaces;j++){
				Indented_string += " ";
			}

			int k = i+1;
			while(str[k] == ' '){
				k++;
			}
			i = k -1;


		}else if(str[i] == ';'){
			Indented_string += str[i];
			
		/*	if(str[i+2] == '}'){
				continue;
			}*/
			int j = i + 1;
			while(str[j] == ' '){
				j++;
			}
			if(str[j] == '}'){
				continue;
			}
			Indented_string += "\n";
			for(int j=0;j<spaces;j++){
				Indented_string += " ";
			}

			int k = i+1;
			while(str[k] == ' '){
				k++;
			}
			i = k -1;
		}else{
			Indented_string += str[i];
		}
	}
	cout<<Indented_string<<"\n";

	return 0;
}