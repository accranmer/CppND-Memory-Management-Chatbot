#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////
    //    delete _chatBot; // Task 0
    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

//void GraphNode::AddEdgeToChildNode(GraphEdge *edge)
void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge) // Task 4
{
    _childEdges.push_back(std::move(edge)); // Task 4
    //_childEdges.push_back(std::unique_ptr<GraphEdge> (edge)); // Task 4
}

//// STUDENT CODE
////
//void GraphNode::MoveChatbotHere(ChatBot *chatbot)
void GraphNode::MoveChatbotHere(ChatBot chatbot) // Task 5
{

    _chatBot = std::move(chatbot);  // Task 5
    //_chatBot->SetCurrentNode(this);
    _chatBot.SetCurrentNode(this);
    
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(_chatBot)); // Task 5
    //_chatBot = nullptr; // invalidate pointer at source  // Task 5
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    //return _childEdges[index];
    return (_childEdges[index]).get(); // Task 4
    ////
    //// EOF STUDENT CODE
}
