class Solution {
public:
    struct Point
    {
        int x, y;
        Point(int x, int y)
        {
            this->x = x;
            this->y = y;
        }
    };

    int orientation(Point p, Point q, Point r)
    {
        int val = (((q.y - p.y) * (r.x - q.x)) - ((q.x - p.x) * (r.y - q.y)));

        if(val == 0) return 0; // colinear
        if(val > 0) return 1; // clockwise
        return 2; // counter-clockwis
    }

    double distance(Point p, Point q)
    {
        return ((p.x - q.x) * (p.x - q.x)) + ((p.y - q.y) * (p.y - q.y));
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {

        int n = trees.size();

        // if size is less than 4, all trees must be included.
        if(n < 4)
            return trees;


        // vector to point for simplicity
        vector<Point> points;
        for(int i = 0; i < n; i++)
        {
            Point obj(trees[i][0], trees[i][1]);
            points.push_back(obj);
        }


        // Finding left most then bottom most point (guaranteed to be in convex hull).
        int start = 0;

        for(int i = 0; i < n; i++)
        if(points[i].x < points[start].x ||
           (points[i].x == points[start].x && points[i].y < points[start].y))
            start = i;


        // storing indices for convex hull points.
        vector<int> ansInd;
        ansInd.push_back(start);

        int p = start;

        // vis array to check if already visited or not.
        vector<bool> vis(n);
        vis[p] = true;

        do
        {
            // choosing any point other than p.
            int q = (p + 1) % n;


            for(int i = 0; i < n; i++)
            {
                // if Counter clockwise orientation for p - i - q is found
                if(orientation(points[p], points[i], points[q]) == 2)
                {
                    // Update q to i.
                    q = i;
                }
            }

            // if no counter-clockwise points are found then
            // it is guaranteed q was counter-clockwise most point
            int farthestColinear = q;

            for(int i = 0; i < n; i++)
            {
                // if p - i - q are colinear
                if(i != p && orientation(points[p], points[i], points[q]) == 0)
                {
                    if(!vis[i])
                    {
                        vis[i] = true;

                        ansInd.push_back(i);
                    }

                    // find farthes Colinear point with p - q from p.
                    if(distance(points[p], points[farthestColinear]) < distance(points[p], points[i]))
                        farthestColinear = i;
                }
            }

            p = farthestColinear;

        } while(p != start);

        vector<vector<int>> ans;

        for(int i = 0; i < ansInd.size(); i++)
            ans.push_back(trees[ansInd[i]]);

        return ans;
    }
};
