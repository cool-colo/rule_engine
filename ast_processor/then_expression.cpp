#include <string>
#include "then_expression.hpp"
#include "rule_entry.hpp"

namespace rule_engine {

void ThenExpression::execute(IDataContext* dctx) {
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

}


