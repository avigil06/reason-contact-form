let component = ReasonReact.statelessComponent("Input");

let make = 
  (
    ~label,
    ~type_,
    ~value,
    ~onChange,
    ~invalid,
    _children
  ) => 
{
  ...component,

  render: _self => {
    <div className={invalid ? "rr-input rr-input__invalid" : "rr-input"}>
      <label className="rr-input__label">
        {ReasonReact.string(label)}
      </label>
      <input
        className="rr-input__field"
        type_
        value
        onChange
      />
    </div>;
  }
}