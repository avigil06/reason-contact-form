// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';


function validate(rule, value) {
  return value.length !== 0;
}

function getError(rule, field) {
  return field + " is required";
}

exports.validate = validate;
exports.getError = getError;
/* No side effect */