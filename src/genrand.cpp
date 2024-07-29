//============================================================================
// Name        : genrand.cpp
// Author      : odity
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <thread>
#include <cstring>
#include <future>
#include <unistd.h>
#include <stdlib.h>
#include <mutex>

#define LIMIT_ 50
int charlen=64;
using namespace std;

unsigned long int count=0;
bool count_calc=0;

void gen_random(char **tmp_gen_string) {
	char ch[charlen+1];

    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    	"!@#$%^&*()_+';'\|/"
        "abcdefghijklmnopqrstuvwxyz";
    int i;
    for(i=0;i<charlen;i++)
    	ch[i]=alphanum[rand() % (sizeof(alphanum) - 1)];
    ch[i+1]='\0';
    *tmp_gen_string=&ch[0];
    //return tmp_gen_string;
}

struct sRand{
	char *str;
    struct sRand *next;
};//*p_tail, *p_begin;
void delete_list(sRand *p_begin)
{
    sRand *p = p_begin;
    while (p != NULL) {
        sRand *tmp;
        tmp = p;
        p = p->next;
        free(tmp->str);
        free(tmp);
    }
}
void calccountinlist(sRand *p_begin)
{
	count_calc=true;

	sRand *p = p_begin;
	count=0;
    while (p->next != NULL) {
    	count+=charlen;
    	p=p->next;
    }
    count_calc=false;
}
sRand* add_list(char* str,sRand *p_end)
{
	sRand *p;
	p=p_end;
	p->str = (char *) malloc(sizeof (char*) * charlen+1);
	//p->str = &str[0];
	strncpy(p->str,&str[0],charlen);
	p->next=(sRand *)malloc(sizeof(sRand));
	p = p->next;
	p->next = NULL;
	//p_end->next = (sRand *)malloc(sizeof(sRand));
	//p->next = p_end;
	//p->next=NULL;
	return p;
}

sRand* gencharwhile(sRand *p_end,sRand *p_begin){
	//sRand *p = p_end;
	char* tmp = (char*) malloc(sizeof(char*)*charlen +1);
	if(count < LIMIT_){
		gen_random(&tmp);
		p_end = add_list(tmp,p_end);
	}
	calccountinlist(p_begin);
	//free(tmp);
	return p_end;
}
sRand* printcharfromlist(sRand *p_begin,FILE* f)
{
	sRand *p = p_begin;
	while(count_calc == true){cout<<"wait"<<endl;}
    if (p != NULL) {
    	sRand *tmp;
        tmp = p;
        fwrite(p->str, sizeof( char*), strlen(p->str), f);
        p = p->next;
        free(tmp->str);
        free(tmp);
    }
    return p;

}
std::mutex m;
//sRand *p_tail, *p_begin;
int main(int argc, char** argv) {
	setlocale(LC_ALL, "");
	if(argv[1])
		charlen=atoi(argv[1]);
	srand((unsigned)time(NULL) * getpid());

	sRand *p_tail, *p_begin;
	/*while(1){
		cout<<gen_random();
	}
*/

	p_begin = (sRand *)malloc(sizeof(sRand));
	p_begin->next = NULL;
	p_tail=p_begin;

	/*while(1){
		p_tail = gencharwhile(p_tail,p_begin);
		cout<<count<<endl;
	}*/
	/*auto future1 = async(std::launch::async, [&p_tail], [&p_begin] {
		if(count < LIMIT_){
			p_tail = add_list(gen_random(),p_tail);
		}
		calccountinlist(p_begin);
	}
	});*/
	FILE *f;
	f = fopen("/tmp/1", "w");
	if (!f)
			exit(EXIT_FAILURE);
	while(true){
		/*future<sRand *> in  = async( gencharwhile,p_tail,p_begin);
		p_tail = in.get();
		in  = async( gencharwhile,p_tail,p_begin);
		p_tail = in.get();
*/
		//in  = async( gencharwhile,p_tail,p_begin);
		//p_tail = in.get();

		p_tail = gencharwhile(p_tail,p_begin);//!!
		p_tail = gencharwhile(p_tail,p_begin);//!!
		p_begin = printcharfromlist(p_begin,f);//!!


		//thread gen(gencharwhile,p_tail,p_begin);
		//gen.detach();

		/*future<sRand *>out  = async( printcharfromlist,p_begin,f);
		p_begin = out.get();
		*/
		//p_tail = gencharwhile(p_tail,p_begin);

		//cout<<p_tail->str;
		//cout<<count<<endl;

		//p_begin = printcharfromlist(p_begin,f);
		//future<sRand *>out  = async( printcharfromlist,p_begin,f);
		//p_begin = out.get();
		//cout<<" "<<count<<endl;
		if(count == LIMIT_)
			break;
	}
	fclose(f);
	delete_list(p_begin);
	//thread gen(gencharwhile,p_tail,p_begin);
	//gen.detach();

	//thread calccount(calccountinlist,p_begin);
	//calccount.detach();

	//while(true)
	//{
		//cout<<count<<endl;
	//}
	return 0;
}
