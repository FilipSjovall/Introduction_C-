#include "editor.h"

#include <string>

using std::string;

using size_type = Editor::size_type;

size_type Editor::get_size() const
{
    return text.size();
}

size_type Editor::find_left_par(size_type pos) const {
    char a;
    char b;
    if(text[pos]==')'){
         a = '(';
         b = ')';
    }
    else if(text[pos]==']'){
         a = '[';
         b = ']';
    }
    else if(text[pos]=='}'){
         a = '{';
         b = '}';
    }
    else
    {
        return string::npos;
    }
    
    int cnt = 0;
    for( int i = pos ; i>0 ; i--){
        
        if(text[i]==a){
            cnt --;
        }
        else if(text[i]==b){
            cnt ++;
        }
        if(cnt==0){
            return i;
        }
    }
}
