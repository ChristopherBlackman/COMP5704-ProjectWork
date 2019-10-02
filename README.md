<hr>

## COMP5704: Parallel Algorithms and Applications in Data Science
### Project Title : Graph Connectivity In Undireced Graphs
### Name : Christopher Blackman
### E-Mail : christopher.blackman@cmail.carleton.ca

<hr>

##### Project Outline : 
In graph theory graph connectivity is the minimum number of vertices, or elements that need to be removed to separate nodes into isolated subgraphs. This feild can be split into two parts : the connectivity of directed graphs, and the connectivity of undirected graphs. In directed graphs we represent connectivity as Strongly Connected Components (SCC). Where a graph is said to be strongly connected if every vertex is reachable from every other vertex. The SCCs of a directed graph form a partition of subgraphs where they themselves are strongly connected. Directed graphs also have weakly connected components where they are defined as the diffrence of the origianl graph 'G', and 'S' the strongly connected components of graph G such that WCC is equal to  G\S. For undirected graphs, since connections are bijective all paths are SCC. Therefore if we are looking for SCC, then we are looking for disjoint subgraphs in 'G'.

There are other problems that come out of the feild of graph connectivity such as cuts.
A cut C=(S,T) of a graph is a partition of V of a graph G=(V,E) into two subsets S and T, such that the cut is the edges that have an endpoint in both S, and T. A cut where it's size or weight is no larger than any-other cut is defined as the min-cut.
However, for the purpose of this report we will only be dealing with undirected graphs.

Tarjan was one of the first papers to compute SCC in directed graphs, and undirected graphs. He used the .. <to be cont.>


 
##### Startup Paper(s):
  - Parallael Minimum Cuts in Near-linear Work and Low Depth https://dl-acm-org.proxy.library.carleton.ca/citation.cfm?id=331608
  - Minimum cuts in near-linear time https://dl-acm-org.proxy.library.carleton.ca/citation.cfm?id=3210377
  - A new approach to the minimum cut problem https://dl.acm.org/citation.cfm?doid=234533.234534
  
##### Deliverables:
  - [x] Project Website (September 17th)
  - [ ] Literature Review (October 1st) : https://github.com/ChristopherBlackman/COMP5704-ProjectWork/blob/master/lit_rev/lit_rev.pdf
  - [ ] Presentation Outline (November 12th)
  - [ ] Slide Presentation (Presentation November 27th, December 4th)
  - [ ] Final paper (December 6th)
  - [ ] Code and Data
##### Relevant References:
  - reference 1
  - reference 2
