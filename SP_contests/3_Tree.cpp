class ASTNode
{
  public:
    virtual ~ASTNode() = default;
    virtual void print() const = 0;
    virtual int get_value() const = 0;
};

class ASTNumberNode : public ASTNode
{
    int val;

  public:
    ASTNumberNode(int val_ = 0) { val = val_; }

    void
    print() const override
    {
        std::cout << val;
    }

    int
    get_value() const override
    {
        return val;
    }

    static NodeOwner
    create(int val)
    {
        return NodeOwner(new ASTNumberNode(val));
    }
};

class ASTPlusNode : public ASTNode
{
    NodeOwner num1, num2;

  public:
    ASTPlusNode(NodeOwner num_obj1, NodeOwner num_obj2) : num1(std::move(num_obj1)), num2(std::move(num_obj2)){};

    static NodeOwner
    create(NodeOwner num_obj1, NodeOwner num_obj2)
    {
        return NodeOwner(new ASTPlusNode(std::move(num_obj1), std::move(num_obj2)));
    }

    void
    print() const override
    {
        std::cout << "(";
        num1->print();
        std::cout << " + ";
        num2->print();
        std::cout << ")";
    }

    int
    get_value() const override
    {
        return num1->get_value() + num2->get_value();
    }
};

class ASTMinusNode : public ASTNode
{
    NodeOwner num1, num2;

  public:
    ASTMinusNode(NodeOwner num_obj1, NodeOwner num_obj2) : num1(std::move(num_obj1)), num2(std::move(num_obj2)){};

    static NodeOwner
    create(NodeOwner num_obj1, NodeOwner num_obj2)
    {
        return NodeOwner(new ASTMinusNode(std::move(num_obj1), std::move(num_obj2)));
    }

    void
    print() const override
    {
        std::cout << "(";
        num1->print();
        std::cout << " - ";
        num2->print();
        std::cout << ")";
    }

    int
    get_value() const override
    {
        return num1->get_value() - num2->get_value();
    }
};

NodeOwner
operator+(NodeOwner num_obj1, NodeOwner num_obj2)
{
    return ASTPlusNode::create(std::move(num_obj1), std::move(num_obj2));
}

NodeOwner
operator-(NodeOwner num_obj1, NodeOwner num_obj2)
{
    return ASTMinusNode::create(std::move(num_obj1), std::move(num_obj2));
}
