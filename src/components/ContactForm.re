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
          let model: array(Validators.field) = [|
            { value: state.name, name: "name" },
            { value: state.email, name: "email" },
            { value: state.description, name: "description" },
          |];
          let errors = Validators.validateForm(model);
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
          invalid={true}
          onChange={event => send(UpdateForm({...state, name: getChangeValue(event)}))} />
        <Input
          label="Reason"
          type_="text"
          value={state.email}
          invalid={false}
          onChange={event => send(UpdateForm({...state, email: getChangeValue(event)}))} />
        <TextArea
          label="Description"
          value={state.description}
          invalid={false}
          onChange={event => send(UpdateForm({...state, description: getChangeValue(event)}))} />
        <div className="flex items-center justify-between">
          <button className="btn">(ReasonReact.string("Send"))</button>
        </div>
      </form>
    </div>
  },
};
