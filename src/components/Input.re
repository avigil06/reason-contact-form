let component = ReasonReact.statelessComponent("Input");

let make = 
  (
    ~label,
    ~type_,
    ~value,
    ~onChange,
    _children
  ) => 
{
  ...component,

  render: _self => {
    <div className="mb-4">
      <label className="block text-grey-darker text-sm font-bold mb-2">
        {ReasonReact.string(label)}
      </label>
      <input
        className="shadow appearance-none border rounded w-full py-2 px-3 text-grey-darker leading-tight focus:outline-none focus:shadow-outlin"
        type_
        value
        onChange
      />
    </div>;
  }
}