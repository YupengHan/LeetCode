string gethostname(string url)
{
  url = url.substr(url.find("//") + 2);
  return url.substr(0, url.find('/'));
}

// Web crawler using standard BFS.
vector<string> crawl(string startUrl, HtmlParser htmlParser) {
  // This is kept so that we dont crawl the same link twice.
  unordered_set<string> st;
  
  // For BFS search.
  queue<string> q;
 
  // Get the hostname.
  string hostname = gethostname(startUrl);
  q.push(startUrl);
  st.insert(startUrl);
 
  // Start BFS.
  while(!q.empty())
  {
    string urlcrawl = q.front();
    q.pop();
    for(auto url : htmlParser.getUrls(urlcrawl))
    {
      if(url.find(hostname) != string::npos &&
        st.find(url) == st.end())
      {
        q.push(url);
        st.insert(url);
      }
    }
  }

  return vector<string>(st.begin(), st.end());

}