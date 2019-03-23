type state = {
  name: string,
  email: string,
  description: string,
};

type action =
  | UpdateForm(state)
  | Validate
  | Submit;

let component = ReasonReact.reducerComponent("ContactForm");

let getChangeValue = event => ReactEvent.Form.target(event)##value;

let handleSubmit = (send, event) => {
  send(Validate);
  ReactEvent.Form.preventDefault(event);
}

let make = _children => {
  ...component,

  initialState: () => {
    name: "",
    email: "",
    description: "",
  },

  reducer: (action, state) =>
    switch (action) {
      | UpdateForm(newState) => ReasonReact.Update(newState)
      | Validate => {
          open Validators;
          let name = validate(NotEmpty, state.name);
          let email = validate(NotEmpty, state.email);
          let description = validate(NotEmpty, state.description);
          Js.log(name ? "True" : "False");
          Js.log(email ? "True" : "False");
          Js.log(description ? "True" : "False");
          ReasonReact.NoUpdate;
        }
      | Submit => ReasonReact.NoUpdate
    },

  render: ({state, send}) => {
    <div className="w-screen h-screen flex content-center justify-center items-center">
      <form noValidate={true} onSubmit={handleSubmit(send)} className="bg-white shadow-md rounded px-8 pt-6 pb-8 mb-4">
        <Input
          label="Full Name"
          type_="text"
          value={state.name}
          onChange={event => send(UpdateForm({...state, name: getChangeValue(event)}))} />
        <Input
          label="Reason"
          type_="text"
          value={state.email}
          onChange={event => send(UpdateForm({...state, email: getChangeValue(event)}))} />
        <TextArea
          label="Description"
          value={state.description}
          onChange={event => send(UpdateForm({...state, description: getChangeValue(event)}))} />
        <div className="flex items-center justify-between">
          <button className="bg-blue hover:bg-blue-dark text-white font-bold py-2 px-4 rounded focus:outline-none focus:shadow-outline">(ReasonReact.string("Send"))</button>
        </div>
      </form>
    </div>
  },
};
