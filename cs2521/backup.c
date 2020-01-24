/*        // s != v != t
        for (int s = 0; s < numV; s++) {
            if (s != v) {    
                // 'ShortestPaths' structure with the source vertex s
                ShortestPaths sps = dijkstra(g, s);
                
                for (int t = 0; t < numV; t++) {
                    
                    if (t != s && t != v) {
                        // the total number of shortest path from node s to t
                        total = total_path (sps, s, t);
                        
                        // the number of these paths that pass through v 
                        pass = pass_path (sps, s, t, v);
                        
                        if (total == 0) {
                            continue;
                        } else {
                            value = value + pass/total;
                        }
                    }    
                }    
            }    
        }        
*/  
