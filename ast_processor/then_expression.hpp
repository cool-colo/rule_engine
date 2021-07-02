#ifndef _RULE_ENGINE_THEN_EXPRESSION_
#define _RULE_ENGINE_THEN_EXPRESSION_

#include <string>

#include "assignment.hpp"
#include "expression_atom.hpp"
#include "node.hpp"

namespace rule_engine {

class RuleEntry;

class ThenExpression: public Node, 
    public IExpressionAtomAcceptor, public IAssignmentAcceptor, public IRuleEntryAcceptor{
public:
    ThenExpression() {}
    virtual void accept_expression_atom(std::shared_ptr<ExpressionAtom> atom) {
        atom_ = atom;
    }

    virtual void accept_assignment(std::shared_ptr<Assignment> assignment) {
        assignment_ = assignment;
    }

    virtual void accept_rule_entry(std::shared_ptr<RuleEntry> entry) {
        rule_entry_ = entry;
    }

    void execute(IDataContext* dctx);
    /*

    void execute(IDataContext* dctx) {
        if(assignment_) {
            assignment_->execute(dctx);
        } else if(atom_) {
            atom_->execute(dctx);
        } else if (rule_entry_){
	    if(rule_entry_->evaluate(dctx)){
	      rule_entry_->execute(dctx);
	    }
	}
    }
    */
private:
    std::shared_ptr<Assignment> assignment_;
    std::shared_ptr<ExpressionAtom> atom_;
    std::shared_ptr<RuleEntry> rule_entry_;
};

}


#endif
