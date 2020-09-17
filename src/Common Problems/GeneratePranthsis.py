def prnts(c,num): 
	if(num > 0): 
		_prnts(c,0,num,0,0); 
	return; 

def _prnts(c,ind,num,start,endd): 
	
	if(endd == num): 
		for i in c: 
			print(i,end = ""); 
		print(); 
		return; 
	else: 
		if(start>endd): 
			c[ind] = '}'; 
			_prnts(c,ind+1,num,start,endd+1); 
		if(start < num): 
			c[ind] = '{'; 
			_prnts(c,ind+1,num,start+1,endd);
            

value = 3; 
countt = 2*value*[""]; 
prnts(countt,value);