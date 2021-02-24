int Graph<Tv, Te>::BFS (int v) 
{
   	Queue<int> Q; 
   	status (v) = DISCOVERED; 
   	Q.enqueue(v); 
   	while (!Q.empty()) 
   	{
      	int v = Q.dequeue();  
      	for(int u = firstNbr(v); -1 < u; u = nextNbr(v, u))
         	if(UNDISCOVERED == status(u)) 
		 	{
            	status(u) = DISCOVERED; 
            	Q.enqueue(u); 
         	} 
  	}
  	return v;
}

int Graph<Tv, Te>::Diameter() 
{
   	int v = BFS(0); 
   	Queue<int> Q; 
   	status(v) = DISCOVERED; 
   	distance(v) = 0;
   	Q.enqueue(v); 
   	while (!Q.empty()) 
   	{
      	int v = Q.dequeue();  
      	for(int u = firstNbr(v); -1 < u; u = nextNbr(v, u))
         	if(UNDISCOVERED == status(u) ) 
		 	{
            	status(u) = DISCOVERED; 
            	distance(u) = distance(v)++;
            	Q.enqueue(u); 
         	} 
   	}
  	return distance(v);
}
 
