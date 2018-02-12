ElementType FindKth( List L, int K ){  
    if(L==NULL){  
        return ERROR;  
    }  
    else{  
        //先将指针移动到位置K   
        while(--K){    
            if(L->Next==NULL){  
                return ERROR;  
            }else{  
                L = L->Next;  
            }  
        }  
    }  
    return L->Data;  
} 
