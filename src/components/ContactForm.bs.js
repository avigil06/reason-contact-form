// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Input$ReactTemplate = require("./Input.bs.js");
var TextArea$ReactTemplate = require("./TextArea.bs.js");
var Validators$ReactTemplate = require("../utilities/Validators.bs.js");

var component = ReasonReact.reducerComponent("ContactForm");

function getChangeValue($$event) {
  return $$event.target.value;
}

function handleSubmit(send, $$event) {
  Curry._1(send, /* Validate */0);
  $$event.preventDefault();
  return /* () */0;
}

function make(_children) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (param) {
              var send = param[/* send */3];
              var state = param[/* state */1];
              return React.createElement("div", {
                          className: "w-screen h-screen flex content-center justify-center items-center"
                        }, React.createElement("form", {
                              className: "bg-white shadow-md rounded px-8 pt-6 pb-8 mb-4",
                              noValidate: true,
                              onSubmit: (function (param) {
                                  return handleSubmit(send, param);
                                })
                            }, ReasonReact.element(undefined, undefined, Input$ReactTemplate.make("Full Name", "text", state[/* name */0], (function ($$event) {
                                        return Curry._1(send, /* UpdateForm */[/* record */[
                                                      /* name */$$event.target.value,
                                                      /* email */state[/* email */1],
                                                      /* description */state[/* description */2]
                                                    ]]);
                                      }), true, /* array */[])), ReasonReact.element(undefined, undefined, Input$ReactTemplate.make("Reason", "text", state[/* email */1], (function ($$event) {
                                        return Curry._1(send, /* UpdateForm */[/* record */[
                                                      /* name */state[/* name */0],
                                                      /* email */$$event.target.value,
                                                      /* description */state[/* description */2]
                                                    ]]);
                                      }), false, /* array */[])), ReasonReact.element(undefined, undefined, TextArea$ReactTemplate.make("Description", state[/* description */2], (function ($$event) {
                                        return Curry._1(send, /* UpdateForm */[/* record */[
                                                      /* name */state[/* name */0],
                                                      /* email */state[/* email */1],
                                                      /* description */$$event.target.value
                                                    ]]);
                                      }), false, /* array */[])), React.createElement("div", {
                                  className: "flex items-center justify-between"
                                }, React.createElement("button", {
                                      className: "btn"
                                    }, "Send"))));
            }),
          /* initialState */(function (param) {
              return /* record */[
                      /* name */"",
                      /* email */"",
                      /* description */""
                    ];
            }),
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */(function (action, state) {
              if (typeof action === "number") {
                if (action !== 0) {
                  return /* NoUpdate */0;
                } else {
                  var model = /* array */[
                    /* record */[
                      /* name */"name",
                      /* value */state[/* name */0]
                    ],
                    /* record */[
                      /* name */"email",
                      /* value */state[/* email */1]
                    ],
                    /* record */[
                      /* name */"description",
                      /* value */state[/* description */2]
                    ]
                  ];
                  Validators$ReactTemplate.validateForm(model);
                  return /* NoUpdate */0;
                }
              } else {
                return /* Update */Block.__(0, [action[0]]);
              }
            }),
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.component = component;
exports.getChangeValue = getChangeValue;
exports.handleSubmit = handleSubmit;
exports.make = make;
/* component Not a pure module */
