#ifndef FUNCTIONS_BUFFER
#define FUNCTIONS_BUFFER

typedef struct buffer{
	int size;
	int half;
	int row;
	int col;
	char* vet;
	int lexemaBegin;
	int forward;
	int lastLoad;

} buffer;

void loadBuffer(buffer* b,FILE * f,int type){

	//type == 0 load first half
	//type == 1 load second half

	int begin,end,i;
	char c;

	if      (type==0){ begin = 0; b->lastLoad = 0; }
	else if (type==1){ begin = b->half; b->lastLoad = 1;}
	else {begin = 0; b->lastLoad = 0;}

	end = begin + b->half-1;
	
	for(i = begin;i<end;i++){
		
		c = getc(f);
		b->vet[i] = c;
		 
		if(c==EOF) break;
		
	}
}

void stepForward(buffer * b, FILE * f){

	b->forward++;

	if(b->forward>=b->size) b->forward = 0;
}

void stepLexemaBegin(buffer * b){

	int i = b->lexemaBegin;
	i++;

	if     (i==b->size-1) i = 0;
	else if(i==b->half-1) i = b->half;

	b->lexemaBegin = i;
}


char readNext(buffer * b,FILE * f){


	if(b->vet[b->forward] == EOF){
		//load buffer
		if(b->forward == b->half-1 && b->lastLoad == 0){
			loadBuffer(b,f,1);
			stepForward(b,f);
		}
		if(b->forward == b->size-1 && b->lastLoad == 1) {
			loadBuffer(b,f,0);
			stepForward(b,f);
		}
	}

	char c = b->vet[b->forward];
	stepForward(b,f);
	

	return c;

}

void backward(buffer *b){

	if(b->forward == 0){
		b->forward = b->size-3;
	}else if(b->forward == b->half){
		b->forward = b->half - 3;
	}else{
		b->forward--;
	}
}

void nextToken(buffer * b){


	int i = b->lexemaBegin;

	int end = b->forward;
	
	while(i != end){

		if(b->vet[i] == '\n') {
			
			b->row++;
			b->col = 1;
		}else if(b->vet[i] != EOF){
			b->col++;
		}

		i++;
		if (i==b->size) i=0;

	}

	b->lexemaBegin = b->forward;

}


char* getLexema(buffer * b){

	char * str = malloc(sizeof(char) * (b->size+1));

	int i = b->lexemaBegin;
	int end = b->forward;
	

	int j = 0;

	while(i!=end){

		if(b->vet[i] != EOF){
			str[j] = b->vet[i];
			j++;
		}
		
		i++;

		if(i == b->size) i=0;
	}
	str[j] = '\0';
	
	return str;

	
}

void initBuffer(buffer * b, int size){

	b->size        = size;
	b->half        = b->size/2;
	b->row         = 1;
	b->col         = 1;
	b->vet         = malloc(sizeof(char)*size);
	b->lexemaBegin = 0;
	b->forward     = b->size - 1;
	b->lastLoad    = 1;

	b->vet[b->half-1] = EOF;
	b->vet[b->size-1] = EOF;
}


#endif