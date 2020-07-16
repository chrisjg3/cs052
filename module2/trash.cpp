class Essay :public GradedActivity

{
private:
double grammar_Score,spelling_Score,length_Score,content_Score;

	
public:
double getgrammar_Score()const

{
return grammar_Score;
}

 

void setgrammar_Score(double s)

{
grammar_Score = s; 
}

 

double getspelling_Score()const

{
return spelling_Score;
}

 

void setspelling_Score(double s)
{
spelling_Score = s;
}
	
double getlength_Score()const

{
return length_Score; 

}
	
	
	
void setlength_Score(double s)

{ 

length_Score = s;

}
double getcontent_Score()const
{
return content_Score; 

}

 

void setcontent_Score(double s)

{
content_Score = s;
}


char getGrade()
{
double score = grammar_Score + spelling_Score + length_Score + content_Score;

	

GradedActivity::setScore(score);
 
char grade = getLetterGrade();

return grade;
}
 

};




int main()
{
	int answerInput;
	
cout<<"Enter points received for grammar:\n";
	cin>>answerInput;
	setgrammar_Score(answerInput);
	
cout<<"Enter points received for spelling:\n";
	cin>>answerInput;
	getspelling_Score(answerInput);
	
cout<<"Enter points received for correct·length:\n";
	cin>>answerInput;
	getlength_Score(answerInput);
	
	
cout<<"Enter points received for content:\n";
	cin>>answerInput;
	setcontent_Score(answerInput);
	
cout<<"Numeric Grade: "<<getScore()<<endl;
	
	
cout<<"Letter Grade: "<<getGrade()<<endl;
	
return 0;	
}