#include <dawn/dawn.hxx>

int main(int argc, char* argv[]) {
  DAWN::CPU runCpu;
  DAWN::Graph graph;
  std::string input_path = argv[1];
  std::string output_path = argv[2];
  std::string prinft = argv[3];
  std::string sourceList = argv[4];
  std::string weighted = argv[5];
  graph.interval = 100;
  if (prinft == "true") {
    graph.prinft = true;
    std::cout << "Prinft source " << graph.source << std::endl;
  } else {
    graph.prinft = false;
  }
  if (weighted == "weighted") {
    graph.weighted = true;
    std::cout << "Weighted Graph" << std::endl;
  } else {
    graph.weighted = false;
  }
  graph.stream = omp_get_num_threads();
  graph.thread = omp_get_num_threads();
  graph.createGraph(input_path, graph);
  graph.readList(sourceList, graph);
  runCpu.runMSSPSG(graph, output_path);

  return 0;
}
// ./mssp_cpu $GRAPH_DIR/XX.mtx ../output.txt false ./sourceList.txt
// unweighted

// ./mssp_cpu $GRAPH_DIR/XX.mtx ../output.txt false ./sourceList.txt weighted
