#include <bits/stdc++.h>  
#include <string>  
class Man;  
class Object  
{  
public:  
    Object()  
    {  
        nPos = 0;  
    }  
public:  
    virtual std::string GetType() {return "Object";}  
    virtual bool eat(Object *pObj, Man *pMan)  
    {  
        return false;  
    }  
public:  
    int nPos;  
};  
  
  
class Man  
{  
public:  
    Man()  
    {  
        nPos = 0;  
    }  
  
    virtual std::string GetType() {return "Man";}  
    bool GoWith(std::vector<Object *> &vecObj, size_t nIndex)   
    {  
        if(nIndex < 0 || nIndex > vecObj.size()-1)  
        {  
            return false;  
        }  
  
        if(nPos != vecObj[nIndex]->nPos)  
        {  
            return false;  
        }  
          
        nPos = 1;  
        vecObj[nIndex]->nPos = 1;  
        for(size_t i = 0; i < vecObj.size(); i++)  
        {  
            for(size_t j = 0; j < vecObj.size(); j++)  
            {  
                if(vecObj[i]->eat(vecObj[j],this) == true)  
                {  
                    nPos = 0;  
                    vecObj[nIndex]->nPos = 0;  
                    return false;  
                }  
            }  
              
        }  
          
        std::string strBorderA = "";  
        std::string strOnBoat = GetType()+" ";  
        std::string strBorderB = "";  
        for(size_t i = 0; i < vecObj.size(); i++)  
        {  
            if(vecObj[i]->nPos == 0)  
            {  
                strBorderA += vecObj[i]->GetType()+" ";  
            }  
            else if(vecObj[i]->nPos == 1)  
            {  
                strOnBoat += vecObj[i]->GetType() +" ";  
            }  
            else  
            {  
                strBorderB += vecObj[i]->GetType() +" ";  
            }  
        }  
        nPos = 2;  
        vecObj[nIndex]->nPos = 2;  
  
        std::cout<<"A: "<<strBorderA<<" [["<<strOnBoat<<"-------------->]] B: "<<strBorderB<<std::endl;  
        return true;  
    }  
  
    bool BackWith(std::vector<Object *> &vecObj, size_t nIndex)    
    {  
        if(nIndex < 0 || nIndex > vecObj.size()-1)  
        {  
            return false;  
        }  
  
        if(nPos != vecObj[nIndex]->nPos)  
        {  
            return false;  
        }  
  
        nPos = 1;  
        vecObj[nIndex]->nPos = 1;  
          
        for(size_t i = 0; i < vecObj.size(); i++)  
        {  
            for(size_t j = 0; j < vecObj.size(); j++)  
            {  
                if(vecObj[i]->eat(vecObj[j],this) == true)  
                {  
                    nPos = 2;  
                    vecObj[nIndex]->nPos = 2;  
                    return false;  
                }  
            }  
  
        }  
          
        std::string strBorderA = "";  
        std::string strOnBoat = GetType()+" ";  
        std::string strBorderB = "";  
        for(size_t i = 0; i < vecObj.size(); i++)  
        {  
            if(vecObj[i]->nPos == 0)  
            {  
                strBorderA += vecObj[i]->GetType()+" ";  
            }  
            else if(vecObj[i]->nPos == 1)  
            {  
                strOnBoat += vecObj[i]->GetType() +" ";  
            }  
            else  
            {  
                strBorderB += vecObj[i]->GetType() +" ";  
            }  
        }  
  
        nPos = 0;  
        vecObj[nIndex]->nPos = 0;  
        std::cout<< "A: "<<strBorderA<<" [[<-------------"<<strOnBoat<<"]] B: "<<strBorderB<<std::endl;  
        return true;  
    }  
  
    bool Back(std::vector<Object *> &vecObj)  
    {  
        nPos = 1;  
        for(size_t i = 0; i < vecObj.size(); i++)  
        {  
            for(size_t j = 0; j < vecObj.size(); j++)  
            {  
                if(vecObj[i]->eat(vecObj[j],this) == true)  
                {  
                    nPos = 2;  
                    return false;  
                }  
            }  
  
        }  
          
        std::string strBorderA = "";  
        std::string strOnBoat = GetType()+" ";  
        std::string strBorderB = "";  
        for(size_t i = 0; i < vecObj.size(); i++)  
        {  
            if(vecObj[i]->nPos == 0)  
            {  
                strBorderA += vecObj[i]->GetType()+" ";  
            }  
            else if(vecObj[i]->nPos == 1)  
            {  
                strOnBoat += vecObj[i]->GetType() +" ";  
            }  
            else  
            {  
                strBorderB += vecObj[i]->GetType() +" ";  
            }  
        }  
  
        nPos = 0;  
        std::cout<< "A: "<<strBorderA<<" [[<-------------"<<strOnBoat<<"]] B: "<<strBorderB<<std::endl;  
        return true;  
    }  
public:  
    int nPos;  
};  
  
class Wolf: public Object  
{  
public:  
    Wolf(){};  
    bool eat(Object *pObj, Man *pMan)  
    {  
        if(!pObj|| !pMan)  
        {  
            return false;  
        }  
  
        if(strcmp(pObj->GetType().c_str(),"Sheep") == 0 && nPos == pObj->nPos && pMan->nPos != nPos)  
        {  
            return true;  
        }  
  
        return false;  
    }  
  
    std::string GetType() {return "Wolf";}  
};  
  
class Sheep: public Object  
{  
public:  
    Sheep(){};  
    bool eat(Object *pObj, Man *pMan)  
    {  
        if(!pObj|| !pMan)  
        {  
            return false;  
        }  
  
        if(strcmp(pObj->GetType().c_str(),"Cabbage") == 0 && nPos == pObj->nPos && pMan->nPos != nPos)  
        {  
            return true;  
        }  
  
        return false;  
    }  
  
    std::string GetType() {return "Sheep";}  
};  
  
class Cabbage: public Object  
{  
public:  
    Cabbage(){};  
    std::string GetType() {return "Cabbage";}  
    bool eat(Object *pObj, Man *pMan)  
    {  
        return false;  
    }  
};
class Object;  
class Man;  
class wolf;  
class Sheep;  
class Cabbage;  
  
bool AllDone(std::vector<Object *> &vecObject)  
{  
 size_t nPassed = 0;  
 for(size_t index = 0; index < vecObject.size(); index++)  
 {  
  if(vecObject[index]->nPos == 2)  
  {  
   nPassed++;  
  }  
 }  
  
 if(nPassed == vecObject.size())  
 {  
  return true;  
 }  
  
 return false;  
}  
int _tmain(int argc,char* argv[])  
{  
 Man man;  
 Object *pObj1 = new Wolf();  
 Object *pObj2 = new Sheep();  
 Object *pObj3 = new Cabbage();  
 std::vector<Object *> vecObject;  
 vecObject.push_back(pObj1);  
 vecObject.push_back(pObj2);  
 vecObject.push_back(pObj3);  
 //  
 size_t i = 0;  
 size_t j = 0;  
 while(i < vecObject.size())  
 {  
  if(AllDone(vecObject))  
  {  
   break;  
  }  
  
  if(man.GoWith(vecObject,i))  
  {  
   if(AllDone(vecObject))  
   {  
    break;  
   }  
     
   if(!man.Back(vecObject))  
   {  
    while(j < vecObject.size())  
    {  
     if(j != i)  
     {  
      if(man.BackWith(vecObject,j))  
      {  
       break;  
      }  
     }  
       
     j++;  
     if(j == vecObject.size())  
     {  
      j = 0;  
     }  
    }  
      
   }  
  }  
  
  i++;  
  if(i == vecObject.size())  
  {  
   i = 0;  
  }  
 }  
   
 return 0;  
}  
