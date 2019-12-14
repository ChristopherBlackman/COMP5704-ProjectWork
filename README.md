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

The problem we will be focusing on is CC in undirected graphs, or WCC in directed graphs. We will be implementing the Afforest algorithm and performing a paper review to fill in gaps/proofs in the original paper.

##### Data Set(s):
- http://users.diag.uniroma1.it/challenge9/download.shtml
 
##### Startup Paper(s):
- https://ieeexplore-ieee-org.proxy.library.carleton.ca/document/8425156/references#references
- https://ieeexplore-ieee-org.proxy.library.carleton.ca/document/6877288/references#references
- https://dl-acm-org.proxy.library.carleton.ca/citation.cfm?id=2733089
- https://www-sciencedirect-com.proxy.library.carleton.ca/science/article/pii/0196677482900086
- https://dl-acm-org.proxy.library.carleton.ca/citation.cfm?id=2612692
##### Deliverables:
  - [x] Project Website (September 17th)
  - [ ] Literature Review (October 1st) : https://github.com/ChristopherBlackman/COMP5704-ProjectWork/blob/master/lit_rev/lit_rev.pdf
  - [x] Presentation Outline (November 12th) https://github.com/ChristopherBlackman/COMP5704-ProjectWork/blob/master/presentation_format/overview.pdf
  - [X] Slide Presentation (Presentation November 27th, December 4th) : https://docs.google.com/presentation/d/18n5dn4Y4MRnG0c3PNT-3uTUZOgMo9L7MzfzVuGIZ91Y/edit
  - [ ] Final paper (December 6th)
  - [ ] Code and Data
##### Relevant References:
- [1]https://ieeexplore-ieee-org.proxy.library.carleton.ca/document/8425156/references#references
- [2]https://ieeexplore-ieee-org.proxy.library.carleton.ca/document/6877288/references#references
- [3]https://dl-acm-org.proxy.library.carleton.ca/citation.cfm?id=2733089
- [4]https://www-sciencedirect-com.proxy.library.carleton.ca/science/article/pii/0196677482900086
- [5]https://dl-acm-org.proxy.library.carleton.ca/citation.cfm?id=2612692
- [6]https://link.springer.com/chapter/10.1007/3-540-45591-4_68
- [7]http://diestel-graph-theory.com/index.html
- [8]https://dl-acm-org.proxy.library.carleton.ca/citation.cfm?id=234534 
- [9]https://dl-acm-org.proxy.library.carleton.ca/citation.cfm?id=331608
- [10]https://dl-acm-org.proxy.library.carleton.ca/citation.cfm?id=3210393
- [11]https://dl.acm.org/citation.cfm?id=263872
- [12]https://link.springer.com/chapter/10.1007/978-0-8176-4842-8_15
- [13]https://dl.acm.org/citation.cfm?id=1942094
- [14]https://dl.acm.org/citation.cfm?doid=362248.362272
- [15]https://dl.acm.org/citation.cfm?id=2503246
- [16]https://ieeexplore.ieee.org/document/4569669
- [17]https://dl.acm.org/citation.cfm?id=550359
- [18]https://www.sciencedirect.com/science/article/pii/0898122181900080
- [19]https://www.sciencedirect.com/science/article/pii/0020019085900249
- [20]https://dl.acm.org/citation.cfm?id=663154
- [21]https://dl.acm.org/citation.cfm?id=362272
- [22]https://dl.acm.org/citation.cfm?id=322235
- [23]https://www.sciencedirect.com/science/article/pii/0020019082901314
- [24]https://dl-acm-org.proxy.library.carleton.ca/citation.cfm?id=739745
- [25]https://dl-acm-org.proxy.library.carleton.ca/citation.cfm?id=305744
- [26]https://dl-acm-org.proxy.library.carleton.ca/citation.cfm?id=254195
- [27]https://dl-acm-org.proxy.library.carleton.ca/citation.cfm?id=182530
- [28]https://dl-acm-org.proxy.library.carleton.ca/citation.cfm?id=359141
- [29]https://dl-acm-org.proxy.library.carleton.ca/citation.cfm?id=214077
- [30]https://dl-acm-org.proxy.library.carleton.ca/citation.cfm?id=106163
- [31]https://dl-acm-org.proxy.library.carleton.ca/citation.cfm?id=203622
- [32]https://dl-acm-org.proxy.library.carleton.ca/citation.cfm?id=358650
- [33]https://dl-acm-org.proxy.library.carleton.ca/citation.cfm?id=72952
- [34]https://dl-acm-org.proxy.library.carleton.ca/citation.cfm?id=586952
- [35]https://dl-acm-org.proxy.library.carleton.ca/citation.cfm?id=1398907
- [36]https://www.sciencedirect.com/science/article/pii/0166218X84900192
- [37]B. Awerbuch and Y. Shiloach. New connectivity and MSF algorithms for Ultracomputer and PRAM. In ICPP, pages 177--187, 1983.
- [38]https://dl-acm-org.proxy.library.carleton.ca/citation.cfm?id=237563
- [39]https://dl-acm-org.proxy.library.carleton.ca/citation.cfm?id=123143
- [40]https://dl-acm-org.proxy.library.carleton.ca/citation.cfm?id=247524
- [41]https://dl-acm-org.proxy.library.carleton.ca/citation.cfm?id=377897
- [42]https://dl-acm-org.proxy.library.carleton.ca/citation.cfm?id=586952
- [43]https://dl-acm-org.proxy.library.carleton.ca/citation.cfm?id=686427
- [44]S. Hambrusch and L. TeWinkel. A study of connected component labeling algorithms on the MPP. In Supercomputing, pages 477--483, 1988.
- [45]S. Goddard, S. Kumar, and J. F. Prins. Connected components algorithms for mesh-connected parallel computers. In Parallel Algorithms: 3rd DIMACS Implementation Challenge, pages 43--58, 1995.
- [46]T.-S. Hsu, V. Ramachandran, and N. Dean. Parallel implementation of algorithms for finding connected components in graphs, 1997
- [47]https://dl-acm-org.proxy.library.carleton.ca/citation.cfm?id=1196220
- [48]https://dl-acm-org.proxy.library.carleton.ca/citation.cfm?id=1079430
- [49]https://dl-acm-org.proxy.library.carleton.ca/citation.cfm?id=2358680
- [50]https://dl-acm-org.proxy.library.carleton.ca/citation.cfm?id=2312018
- [51]https://dl-acm-org.proxy.library.carleton.ca/citation.cfm?id=746654
- [53]A. Krishnamurthy, S. S. Lumetta, D. E. Culler, and K. Yelick. Connected components on distributed memory machines. In Parallel Algorithms: 3rd DIMACS Implementation Challenge, pages 1--21, 1994.
- [54]https://dl-acm-org.proxy.library.carleton.ca/citation.cfm?id=231641
- [55]E. Caceres, H. Mongelli, C. Nishibe, and S. W. Song. Experimental results of a coarse-grained parallel algorithm for spanning tree and connected components. In High Performance Computing & Simulation, pages 631--637, 2010.
- [56]https://dl-acm-org.proxy.library.carleton.ca/citation.cfm?id=1869229
- [57]J. Soman, K. Kishore, and P. J. Narayanan. A fast GPU algorithm for graph connectivity. In IPDPS, pages 1--8, 2010.
- [58]https://dl-acm-org.proxy.library.carleton.ca/citation.cfm?id=2192614
- [59]https://dl.acm.org/citation.cfm?id=2059488
