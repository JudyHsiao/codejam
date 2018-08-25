#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

template <typename T>

string join(const T& v, const string& delim) {
    ostringstream s;
    for (const auto& i : v) {
        if (&i != &v[0]) {
            s << delim;
        }
        s << i;
    }
    return s.str();
}

const int maxn = 100 + 5;

struct XPoint{
    double x;
    int id;
    int type;   //0: start, 1: end

    bool operator < (const XPoint& rhs) const {
        return x < rhs.x;
    }

    XPoint(double xx, int index, int tt ) {
        x = xx;
        id = index;
        type =tt;
    }
};




struct Building {
  int id;
  double x, y, w, d, h;
} b[maxn];

struct YCmp
{
	bool operator () (const Building& a, const Building& b) const
	{
        if (a.y == b.y) {
            return a.x < b.x;
        }
		return a.y < b.y;
	}
};

struct HCmp
{
	bool operator () (const Building& a, const Building& b) const
	{
        if (a.h == b.h) {
            return a.y < b.y;
        }
		return a.h > b.h;

	}
};

int main() {
    int n;
    int kase = 1;
    while(scanf("%d", &n) ==1 && n) {
        
        double x, y, w, d, h;
        vector <XPoint> X;
        for (int i =0; i <n ;i++){
            scanf("%lf%lf%lf%lf%lf", &x, &y,&w,&d,&h);
            X.push_back(XPoint(x, i, 0));
            X.push_back(XPoint(x+w, i, 1));
            b[i].x = x;
            b[i].y = y;
            b[i].w = w;
            b[i].d = d;
            b[i].h = h;
            b[i].id = i+1;
        }
        sort(X.begin(), X.end());
        
        int i = 0;
        multiset <Building, YCmp> Y;
        multiset <Building, HCmp> H;
        vector <int> ans;
        set<int>ans_set;
        while (i < 2*n) {
            do {
                int id = X[i].id;
                if (X[i].type == 0) {
                    Y.insert(b[id]);
                    H.insert(b[id]);
                } else {
                    Y.erase(b[id]);
                    H.erase(b[id]);
                }
                i++;
                if (i==2*n) {
                    break;
                }

            } while(X[i].x == X[i-1].x);
   
            if (( Y.size() > 0 && ans_set.count(Y.begin()->id) ==0)) {
                ans.push_back(Y.begin()->id);
                ans_set.insert(Y.begin()->id);
            }
            
            if (( H.size() > 0 && ans_set.count(H.begin()->id) ==0)) {
                ans.push_back(H.begin()->id);
                ans_set.insert(H.begin()->id);
            }


        }
        
        if(kase > 1) {
            printf("\n");
        }

        cout << "For map #"<< kase<<", the visible buildings are numbered as follows:\n";
        cout << join(ans, " ") << "\n";
        kase++;
    }
    
}