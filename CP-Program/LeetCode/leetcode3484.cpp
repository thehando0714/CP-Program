class Spreadsheet {
public:
    map<int,map<char,int>>info;//ind,a,num
    Spreadsheet(int rows) {
        map<char,int>tmp1;
        for(int i=0;i<26;i++){
            tmp1['Z'-i]=0;
        }
        for(int i=1;i<=rows;i++){
            info[i]=tmp1;
        }
    }
    
    void setCell(string cell, int value) {
        int num=0;
        
        for(int i=1;i<cell.size();i++){
            num=num*10+(cell[i]-'0');
        }
        
        info[num][cell[0]]=value;
    }
    
    void resetCell(string cell) {
        int num=0;
        for(int i=1;i<cell.size();i++){
            num=num*10+(cell[i]-'0');
        }
        info[num][cell[0]]=0;
    }
    
    int getValue(string formula) {
        
        int num1=0,num2=0;
        bool fir=true,fir2=true;  
        char word1='[',word2='[';
        for(int i=1;i<formula.size();i++){
            if(fir&&isdigit(formula[i])){
                num1=num1*10+(formula[i]-'0');
            }
            else if(fir2&&isalpha(formula[i])){
                word1=formula[i];
                fir2=false;
            }
            else if(!fir2&&isalpha(formula[i])){
                word2=formula[i];
            }
            else if(formula[i]=='+'){
                fir=false;
                fir2=false;
            }
            else if(!fir&&isdigit(formula[i])){
                num2=num2*10+(formula[i]-'0');
            }
        }
        int ans=0;
        if(word1!='['&&info.count(num1)){
            ans+=info[num1][word1];
        }
        else if(word1=='['){
            ans+=num1;
        }
        if(word2!='['&&info.count(num2)){
            ans+=info[num2][word2];
        }
        else if(word2=='['){
            ans+=num2;
        }
        return ans;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */