struct cmp{
  bool operator()(pair<int,string> p1,pair<int,string> p2)const{
      if(p1.first==p2.first)
          return p1.second<p2.second;
      return p1.first>p2.first;
  }  
};