int bsearch(int array[], int start, int end, int data){
        
                if(start > end)
                        return -1;

                int middle = start + end ;
                                middle = middle / 2 ;

                if(array[middle]<data)
                        return bsearch(array,middle+1,end,data);

                if(array[middle]>data)
                        return bsearch(array,start,middle-1,data);
                
                return 1;
        
}

