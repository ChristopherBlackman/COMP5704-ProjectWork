<hr>

## COMP5704: Parallel Algorithms and Applications in Data Science
### Project Title : Parallel Minimum Cuts in a Graph
### Name : Christopher Blackman
### E-Mail : christopher.blackman@cmail.carleton.ca

<hr>

##### Project Outline : 
A cut C=(S,T) of a graph is a partition of V of a graph G=(V,E) into two subsets S and T, such that the cut is the edges that have an endpoint in both S, and T.
A cut where it's size or weight is no larger than any-other cut is defined as the min-cut.

David R. Krager, and Clifford Stein first proved a new sequential approach to Minimum Cuts in graphs.
From this point David R. Krager showed that it was possible to parallize this algorithm. My project will be dealing with implementing David R. Krager's parallal algorithm, and the improvement done to algorithm seen in the paper by Barabara Geissmann, and Lukas Gianiazzi. The chosen model of computation will be Parrallel Random Acess Memory (PRAM), which consits of a set of p processors each connected to an unbounded shared memory. Reading, computing, and writing operations take O(1) time; furthermore we allow multiple processors to read from the same memoery location, but fobid multiple processors to write to the same location. Based on this model work will most likely be done on one machine.

My goal is to be able to implement the parallel algorithm proposed by Barabara Geissmann, and Lukas Gianiazzi, the parallel algorithm proposed by David R. Krager, and his sequential equilivent. For testing I will be measuring performance on diffrent graphs: k-regular, complete, cyclic, acyclic, and possibly real data sets. Hopfully by doing so we can show similar running times as mentioned in the paper.


 
##### Startup Paper(s):
  - Parallael Minimum Cuts in Near-linear Work and Low Depth https://dl-acm-org.proxy.library.carleton.ca/citation.cfm?id=331608
  - Minimum cuts in near-linear time https://dl-acm-org.proxy.library.carleton.ca/citation.cfm?id=3210377
  - A new approach to the minimum cut problem https://dl.acm.org/citation.cfm?doid=234533.234534
  
##### Deliverables:
  - [x] Project Website (September 17th)
  - [ ] Literature Review (October 1st)
  - [ ] Presentation Outline (November 12th)
  - [ ] Slide Presentation (Presentation November 27th, December 4th)
  - [ ] Final paper (December 6th)
  - [ ] Code and Data
##### Relevant References:
  - reference 1
  - reference 2
